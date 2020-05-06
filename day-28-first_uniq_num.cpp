// Problem link: Gone back to Private access

#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

class FirstUnique {
   private:
    list<int> uniqueNums;
    unordered_map<int, int> counts;
    unordered_map<int, list<int>::iterator> numsPos;

   public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            counts[num]++;
        }

        for (int num : nums) {
            int count = counts[num];
            if (count == 1) {
                uniqueNums.push_back(num);

                auto uniqueNumsEndPos = uniqueNums.end();
                uniqueNumsEndPos--;
                numsPos[num] = uniqueNumsEndPos;
            }
        }
    }

    int showFirstUnique() {
        return uniqueNums.empty() ? -1 : uniqueNums.front();
    }

    void add(int value) {
        int count = counts[value];

        // new num
        if (count == 0) {
            counts[value]++;
            uniqueNums.push_back(value);

            auto uniqueNumsEndPos = uniqueNums.end();
            uniqueNumsEndPos--;
            numsPos[value] = uniqueNumsEndPos;
        }

        // unique num
        else if (count == 1) {
            counts[value]++;

            // remove it from unique nums
            auto numPos = numsPos[value];
            uniqueNums.erase(numPos);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

int main() {
}
