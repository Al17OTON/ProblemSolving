#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct Car {
    int hour, min;
    int id;
    int fee;
    int total_min;
    bool out;
    
    bool operator < (const Car& o) const {
        return id > o.id;
    }
};

int get_passed_min(const Car& car, int hour, int min);
int get_hour(const string& record);
int get_min(const string& record);
int get_id(const string& record);
bool is_out(const string& record);
int get_fee(const Car& car);

int basic_min, basic_fee, after_min, after_fee;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<int, Car> map;
    priority_queue<Car> pq;
    
    basic_min = fees[0];
    basic_fee = fees[1];
    
    after_min = fees[2];
    after_fee = fees[3];
    
    for(string record : records) {
        int hour = get_hour(record);
        int min = get_min(record);
        int id = get_id(record);
        bool out = is_out(record);
        
        unordered_map<int, Car>::iterator iter = map.find(id);
        
        if(!out) {
            if(iter == map.end()) {
                map.insert({id, {hour, min, id, 0, 0, false}});
            } else {
                iter->second.hour = hour;
                iter->second.min = min;
                iter->second.out = false;
            }
            
        } else {
            iter->second.out = true;
            iter->second.total_min += get_passed_min(iter->second, hour, min);
        }
    }
    
    for(const pair<const int, Car>& kv : map) {
        Car car = kv.second;
        if(!car.out) {
            car.total_min += get_passed_min(car, 23, 59);
        }
        car.fee = get_fee(car);
        pq.push(car);
    }
    
    while(!pq.empty()) {
        Car car = pq.top();
        pq.pop();
        
        answer.push_back(car.fee);
    }
    
    return answer;
}

int get_passed_min(const Car& car, int hour, int min) {
    return (hour * 60 + min) - (car.hour * 60 + car.min);
}

int get_fee(const Car& car) {
    int total_min = car.total_min;
    
    if(total_min <= basic_min) return basic_fee;
    
    int left_min = total_min - basic_min;
    
    return ((left_min + after_min - 1) / after_min) * after_fee + basic_fee;
}

int get_hour(const string& record) {
    return stoi(record.substr(0, 2));
}

int get_min(const string& record) {
    return stoi(record.substr(3, 2));
}

int get_id(const string& record) {
    return stoi(record.substr(6, 4));
}

bool is_out(const string& record) {
    return record[11] != 'I';
}