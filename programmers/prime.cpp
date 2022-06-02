#include <iostream>
#include <vector>
using namespace std;

int visited[52];
vector<int> vec;
int result = 0;

bool is_prime(int num)
{
	int count = 0;

	for (int i = 3; i <= num / 2; i++)
	{
		if (num % i == 0)
			count++;
		if (count >= 1)
			return false;
	}
	if (count == 0)
		return true;
	return false;
}
void recursive(int idx, int count, vector<int> nums)
{
	if (count == 3)
	{
		int sum = 0;
		for (int i = 0; i < 3; i++)
			sum += vec[i];
		if (is_prime(sum))
			result++;
		return;
	}
	for (int i = idx; i < nums.size(); i++)
	{
		if (visited[i])
			continue;
		visited[i] = 1;
		vec.push_back(nums[i]);
		recursive(i, count + 1, nums);
		vec.pop_back();
		visited[i] = 0;
	}
}

// nums_len은 배열 nums의 길이입니다.
int solution(vector<int> nums) {
    recursive(0, 0, nums);
    return result;
}