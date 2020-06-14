#include "pch.h"
#include "Tag.h"
#include <iostream>

Tag::Tag(const bool isCloseTag)
{
	this->isCloseTag = isCloseTag;
}

bool Tag::getIsCloseTag() const
{
	return isCloseTag;
}

void Tag::addNextTag(Tag * nextTag)
{
	nextTags.push_back(nextTag);
}

size_t Tag::getNextTagsSize() const
{
	return nextTags.size();
}

Tag*& Tag::operator[](size_t index)
{
	return nextTags[index];
}

Tag::~Tag()
{
	for (Tag* tag : nextTags)
	{
		deleteTags(tag);
	}
}

void Tag::deleteTags(Tag *& crrTag)
{
	if (crrTag == nullptr)
	{
		return;
	}
	while (crrTag->getNextTagsSize() != 0)
	{
		deleteTags(crrTag->nextTags[crrTag->getNextTagsSize() - 1]);
		crrTag->nextTags.pop_back();
	}
	delete crrTag;
}
