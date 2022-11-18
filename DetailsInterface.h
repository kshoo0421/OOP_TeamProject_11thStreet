#pragma once

class DetailsInterface
{
public :
	virtual void init_details() = 0;
	virtual void modify_details() = 0;
	virtual void display_details() const = 0;
};