#pragma once
#include <vector>

using namespace std;

class Tag
{
public:
	Tag(const bool isCloseTag = false);
	virtual const int getType() = 0;
	bool getIsCloseTag() const;
	void addNextTag(Tag* nextTag);
	size_t getNextTagsSize() const;
	Tag*& operator[] (size_t index);
	virtual vector<double> calculate(vector<double> values) = 0;
	~Tag();
private:
	bool isCloseTag;
	vector<Tag*> nextTags;
	void deleteTags(Tag *& crrTag);
};