#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE


void ULListStr::push_back(const std::string& val)
{
	  if (empty())     //if list is empty, this item becomes the head and tail
    {
			Item* newNode = new Item(); 
      newNode->next = NULL;
			newNode->prev = NULL;
			newNode->val[newNode->last] = val; //puts value at the last element of the array in this node.
      head_ = newNode; 
      tail_ = newNode;		
			tail_->last =	tail_->last+1;
			size_ = size_ +1;
    }
    else //if the list already has nodes
    { 
   
	if (tail_->last==ARRSIZE ){ // if the array in the last node is full, this string needs to be put in a new node's array
	    Item* newNode = new Item(); //allocates node
    	newNode->val[0] = val;        //puts the new value into node
			newNode->next = NULL;  //regardless if this list is empty/or  the only item, it is becoming the tail
			tail_->next = newNode;
      newNode->prev = tail_;
      tail_ = newNode;

			tail_->last = tail_->last +1;
			size_ = size_ +1;
	} 
	else {
		tail_->val[tail_->last] = val;
		tail_->last = tail_->last +1;
	}
}
}

void ULListStr::pop_back()
{
	tail_->val[(tail_->last)-1] = nullptr; //last-1 because last is exclusive, meaning last actually points to the element AFTER the actual last item
	tail_->last = tail_->last -1;
}


void ULListStr::push_front(const std::string& val)
{
	if (empty())     //if list is empty, this item becomes the head and tail    //should this be at index 9 of first node or index 0?
    {
			Item* newNode = new Item(); 
      newNode->next = NULL;
			newNode->prev = NULL;
			newNode->val[9] = val; //puts value at the last element of the array in this node.
			newNode->last = ARRSIZE;
			newNode->first = 9;
      head_ = newNode; 
      tail_ = newNode;
			size_ = size_ +1;
    }
    else //if the list already has nodes
    { 
	if (head_->first != 0){ //if first does not = 0 then there is array space in front of first
			head_->val[(head_->first)-1] = val; //first-1, because we want this element to now be in front of the previous first
			head_->first = head_->first -1; //update first variable to reflect this change
			head_->last = ARRSIZE;
	}
	else{ //first was actually occupied, and we need to create a new head node to store this new value
		Item* newNode = new Item(); //allocates node
    newNode->val[ARRSIZE-1] = val;        //puts new value into node's array's last element (index 9)
		newNode->last = ARRSIZE;
		newNode->first = ARRSIZE-1;

    newNode->prev = NULL;
		newNode->next = head_;
		head_->prev = newNode;
		head_ = newNode;
		size_ = size_ +1;
	}
		}

}


void ULListStr::pop_front(){

	if (head_->first == 9 ){ //if popping front on an array with only one element
	head_->val[9]= nullptr;
	head_->first = 0;
	}
	else {
		head_->first = head_->first +1; // new first array position is previous first+1;
		head_->val[(head_->first)-1]= nullptr;
	}
	
}


std::string const & ULListStr::back() const
{
	return tail_->val[tail_->last];
}

std::string const & ULListStr::front() const
{
	return head_->val[head_->first];
}


std::string* ULListStr::getValAtLoc(size_t loc) const
{
	int node = loc/10; //round down  get node
 	int index = loc % 10;    //get index 

	Item* temp = new Item();
	temp = head_;
	for (int i=0; i<node; i++)
	{
		temp = temp->next; //at this point, temp will be pointing to the correct node
		return &temp->val[index];
	}
return &temp->val[index]; // if node is 0
}








//

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
