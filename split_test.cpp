#include <iostream>
#include "split.h"
#include "split.cpp"
#include <cstddef>

//function to print linked list
void printList(Node* head)
{
	Node* temp = head;

	// Check for empty list.
	if (head == NULL) {
		std::cout << "List empty" << std::endl;
		return;
	}

	// Traverse the list.
	while (temp != NULL) {
		std::cout << temp->value << " ";
		temp = temp->next;
	}
}


int main(){

	Node* odds = new Node(NULL, nullptr);
	Node* evens = new Node(NULL, nullptr);


	Node* odds1 = new Node(NULL, nullptr);
	Node* evens1 = new Node(NULL, nullptr);

	Node* odds2 = new Node(NULL, nullptr);
	Node* evens2 = new Node(NULL, nullptr);

	Node* odds3 = new Node(NULL, nullptr);
	Node* evens3 = new Node(NULL, nullptr);

	Node* odds4 = new Node(NULL, nullptr);
	Node* evens4 = new Node(NULL, nullptr);


	
	

	//Linked List: 5, 7, 13, 33, 40     -- Test 1
	Node* oneE = new Node(40, nullptr);
	Node* oneD = new Node(33, oneE);
	Node* oneC = new Node(13, oneD);
	Node* oneB = new Node(7, oneC);
	Node* oneA = new Node(5, oneB);
	
	std::cout << "Original List: ";
	printList(oneA);
  std::cout << std::endl;

	split(oneA, odds, evens);

	std::cout << "Odd List: ";
	printList(odds);
  std::cout << std::endl;

	std::cout << "Even List: ";
	printList(evens);
  std::cout << std::endl;

	std::cout << "Original List after Split Function: ";
	printList(oneA);
  std::cout << std::endl;


	//Linked List: 2, 2, 2, 2, 2    -- Test 2    all even
	Node* twoE = new Node(2, nullptr);
	Node* twoD = new Node(2, twoE);
	Node* twoC = new Node(2, twoD);
	Node* twoB = new Node(2, twoC);
	Node* twoA = new Node(2, twoB);

	std::cout << "Original List: ";
	printList(twoA);
  std::cout << std::endl;

	split(twoA, odds1, evens1);

	std::cout << "Odd List: ";
	printList(odds1);
  std::cout << std::endl;

	std::cout << "Even List: ";
	printList(evens1);
  std::cout << std::endl;

	std::cout << "Original List after Split Function: ";
	printList(twoA);
  std::cout << std::endl;

	//Linked List: 0 100 100 150 177 209 300 300    -- Test 3
	Node* threeH = new Node(300,nullptr);
	Node* threeG = new Node(300, threeH);
	Node* threeF = new Node(209, threeG);
	Node* threeE = new Node(177, threeF);
	Node* threeD = new Node(150,threeE);
	Node* threeC = new Node(100, threeD);
	Node* threeB = new Node(100, threeC);
	Node* threeA = new Node(0, threeB);

	std::cout << "Original List: ";
	printList(threeA);
  std::cout << std::endl;

	split(threeA, odds2, evens2);

	std::cout << "Odd List: ";
	printList(odds2);
  std::cout << std::endl;

	std::cout << "Even List: ";
	printList(evens2);
  std::cout << std::endl;

	std::cout << "Original List after Split Function: ";
	printList(threeA);
  std::cout << std::endl;


	//Linked List: 13, 57, 103, 203, 567    -- Test 4  all odd
	Node* fourE = new Node(567, nullptr);
	Node* fourD = new Node(203, fourE);
	Node* fourC = new Node(103, fourD);
	Node* fourB = new Node(57, fourC);
	Node* fourA = new Node(13, fourB);


	std::cout << "Original List: ";
	printList(fourA);
  std::cout << std::endl;

	split(fourA, odds3, evens3);

	std::cout << "Odd List: ";
	printList(odds3);
  std::cout << std::endl;

	std::cout << "Even List: ";
	printList(evens3);
  std::cout << std::endl;

	std::cout << "Original List after Split Function: ";
	printList(fourA);
  std::cout << std::endl;

	//Linked List: 67    --       Test 5  one item
	Node* fiveA = new Node(67,nullptr);

	std::cout << "Original List: ";
	printList(fiveA);
  std::cout << std::endl;

	split(fiveA, odds4, evens4);

	std::cout << "Odd List: ";
	printList(odds4);
  std::cout << std::endl;

	std::cout << "Even List: ";
	printList(evens4);
  std::cout << std::endl;

	std::cout << "Original List after Split Function: ";
	printList(fiveA);
  std::cout << std::endl;


}