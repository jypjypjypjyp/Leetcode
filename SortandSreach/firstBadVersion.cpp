#include "main.h"

bool isBadVersion(int version) {
	return versions[version - 1];
}

int firstBadVersion(int n) {
	int front = 1, rear = n;
	while (rear != front) {
		if (isBadVersion((front + rear) / 2)) {
			rear = (front + rear) / 2;
		}
		else {
			front = (front + rear) / 2 + 1;
		}
	}
	return front;
}
