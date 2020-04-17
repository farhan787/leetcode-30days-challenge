// Problem link: https://leetcode.com/problems/product-of-array-except-self

#include <iostream>
#include <vector>
using namespace std;

// Time complexity = O(n); where n = nums size
// Space complexity = O(n)
vector<int> productExceptSelf1(vector<int>& nums) {
    vector<int> products((int)nums.size(), 1);

    vector<int> prefixProd((int)nums.size(), 1);
    prefixProd[0] = 1;
    for (int i = 1; i < (int)prefixProd.size(); ++i) {
        prefixProd[i] = nums[i - 1] * prefixProd[i - 1];
    }

    vector<int> suffixProd((int)nums.size(), 1);
    suffixProd[(int)suffixProd.size() - 1] = 1;
    for (int i = (int)suffixProd.size() - 2; i >= 0; --i) {
        suffixProd[i] = nums[i + 1] * suffixProd[i + 1];
    }

    for (int i = 0; i < (int)products.size(); ++i) {
        products[i] = prefixProd[i] * suffixProd[i];
    }

    return products;
}

// Time complexity = O(n); where n = nums size
// Space complexity = O(1)
vector<int> productExceptSelf2(vector<int>& nums) {
    vector<int> products((int)nums.size(), 0);

    int numsProduct = 1;
    int zeroCount = 0;

    for (int num : nums) {
        if (num == 0) {
            ++zeroCount;
            continue;
        }
        numsProduct *= num;
    }

    if (zeroCount > 1) {
        return products;
    }

    for (int i = 0; i < (int)nums.size(); ++i) {
        int num = nums[i];

        if (zeroCount > 0 && num != 0) {
            products[i] = 0;
        } else if (zeroCount > 0 && num == 0) {
            products[i] = numsProduct;
        } else {
            int productExceptSelf = numsProduct / num;
            products[i] = productExceptSelf;
        }
    }

    return products;
}

int main() {
    vector<int> nums = {1, 2, 0, 3, 4};
    vector<int> products = productExceptSelf2(nums);

    for (int product : products) {
        cout << product << ", ";
    }
    cout << endl;
}
