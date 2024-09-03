/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* dummyNode = new PolyNode();
        PolyNode* cur = dummyNode;
        
        while (poly1 && poly2) {
            if (poly1->power > poly2->power) {
                cur->next = new PolyNode(poly1->coefficient, poly1->power); 
                poly1 = poly1->next;
            } else if (poly1->power == poly2->power) {
                int newCoeff = poly1->coefficient + poly2->coefficient;
                if (newCoeff != 0) {
                    cur->next = new PolyNode(newCoeff, poly1->power);
                    cur = cur->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            } else {
                cur->next = new PolyNode(poly2->coefficient, poly2->power);  
                poly2 = poly2->next;
            }
            if (cur->next) cur = cur->next;
        }
        
        if (poly1) cur->next = poly1;
        if (poly2) cur->next = poly2;
        
        
        return dummyNode->next;
    }
};