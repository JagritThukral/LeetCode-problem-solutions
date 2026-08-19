class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end());
        std::priority_queue<int, std::vector<int>, std::greater<int>> free;
        for (int i = 0; i < n; ++i) {
            free.push(i);
        }
        std::priority_queue<std::pair<long long, int>,
                            std::vector<std::pair<long long, int>>,
                            std::greater<std::pair<long long, int>>>
            busy;
        vector<int> count(n, 0);
        for (const auto& meeting : meetings) {
            int s = meeting[0];
            int e = meeting[1];
            int duration = e - s;
            while (!busy.empty() && busy.top().first <= s) {
                free.push(busy.top().second);
                busy.pop();
            }
            if (!free.empty()) {
                int room = free.top();
                free.pop();
                busy.push({e, room});
                count[room]++;
            } else {
                std::pair<long long, int> earliest_meeting = busy.top();
                busy.pop();
                long long next_available_time = earliest_meeting.first;
                int room = earliest_meeting.second;

                busy.push({next_available_time + duration, room});
                count[room]++;
            }
        }
        int max_room = 0;
        for (int i = 1; i < n; ++i) {
            if (count[i] > count[max_room]) {
                max_room = i;
            }
        }

        return max_room;
    }
};