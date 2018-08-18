#include "main.h"

void sortColors(vector<int>& nums) {
	int A = 0, B = nums.size() - 1;
	int Ahead = -1, Aend = -1, Bhead = -1, Bend = -1;
	bool request = false, wait = false;
	while (A < B) {
		//A
		wait = false;
		while (A < B) {
			switch (nums[A])
			{
			case 0:
				if (Ahead != -1) {
					nums[Ahead] = 0;
					nums[A] = 1;
					Ahead++; Aend++;
				}
				break;
			case 1:
				if (Ahead != -1) {
					Aend++;
				}
				else {
					Ahead = A;
					Aend = A;
				}
				break;
			case 2:
				if (request) {
					nums[A] = 0;
					nums[B] = 2;
					request = false;
					A--;
				}
				else {
					request = true;
					wait = true;
				}
				break;
			}
			if (wait) break;
			A++;
		}
		//B
		wait = false;
		while (A < B) {
			switch (nums[B])
			{
			case 2:
				if (Bhead != -1) {
					nums[Bhead] = 2;
					nums[B] = 1;
					Bhead--; Bend--;
				}
				break;
			case 1:
				if (Bhead != -1) {
					Bend--;
				}
				else {
					Bhead = B;
					Bend = B;
				}
				break;
			case 0:
				if (request) {
					nums[A] = 0;
					nums[B] = 2;
					request = false;
					B++;
				}
				else {
					request = true;
					wait = true;
				}
				break;
			}
			if (wait) break;
			B--;
		}
	}
	if (nums[A] == 0 && Ahead != -1) {
		nums[A] = 1;
		nums[Ahead] = 0;
	}
	else if (nums[B] == 2 && Bhead != -1) {
		nums[B] = 1;
		nums[Bhead] = 2;
	}
}