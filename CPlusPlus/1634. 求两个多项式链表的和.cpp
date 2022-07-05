// 需要特别注意处理求和之后值为零的情况
#include "include/linked_list.hpp"
class Solution {
public:
	PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2)
	{
		PolyNode* dummy = new PolyNode();
		PolyNode* cursor = dummy;
		while (poly1 && poly2) {
			if (poly1->power > poly2->power) {
				cursor->next = poly1;
				cursor = cursor->next;
				poly1 = poly1->next;
			} else if (poly1->power < poly2->power) {
				cursor->next = poly2;
				cursor = cursor->next;
				poly2 = poly2->next;
			} else {
				poly1->coefficient = poly1->coefficient + poly2->coefficient;
				if (poly1->coefficient) {
					cursor->next = poly1;
					cursor = cursor->next;
				}
				poly1 = poly1->next;
				poly2 = poly2->next;
			}
		}
		if (poly1)
			cursor->next = poly1;
		else
			cursor->next = poly2;
		return dummy->next;
	}
};
