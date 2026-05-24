class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i=0; i<position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());

        stack<float> st; //time
        for (auto& car: cars) {
            float speed = (1.0 * (target - car.first) / car.second);
            if (st.empty() || st.top() < speed) {
                st.push(speed);
            }
        }

        return st.size();
    }
};
