#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;


class ChairType
{
	string color;
	string texture;
	string style;
public:
	ChairType(string c, string t, string s) :color(c), texture(t), style(s) {}
	bool operator==(ChairType& obj) { if (this->color == obj.color && this->texture == obj.texture && this->style == obj.style)return 1; return 0; }
};


class ChairFactory
{
	static vector<ChairType>ChairTypes;
public:
	static ChairType& getChairType(string color, string texture, string style)
	{
		if (find(ChairTypes.begin(), ChairTypes.end(), ChairType(color, texture, style)) == ChairTypes.end())
		{
			ChairTypes.push_back(ChairType(color, texture, style));
			return *(find(ChairTypes.begin(), ChairTypes.end(), ChairType(color, texture, style)));
		}
		return *(find(ChairTypes.begin(), ChairTypes.end(), ChairType(color, texture, style)));
	}
};


class Chair
{
	ChairType* ct;
public:
	Chair(string c,string t,string s) 
	{		
		*ct = ChairFactory::getChairType(c, t, s);
	}
};


class Theatre
{
	vector<Chair> chairs;
public:
	void addChair(string color,string texture,string style) 
	{ 
		chairs.push_back(Chair(color, texture, style));		
	}
};