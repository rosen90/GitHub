#include "State.h"


State::State(string name_, int allVotes_, int numberOfParies_, int partialVotes_[], string partiesNames_[])
{
	//this->name = new string(name_);
	name = new char[name_.size()];
	strcpy(name, name_.c_str());
	this->allVotes = allVotes_;
	this->numberOfParies = numberOfParies_;

//	partialVotes = new int[numberOfParies];
	this->partialVotes = partialVotes_;

	//this->partiesNames = partiesNames_;


	for(int i = 0; i < numberOfParies_; ++i)
	{
		partiesNames[i] = new char[partiesNames_[i].size()];
		strcpy(partiesNames[i], partiesNames_[i].c_str() );
	}

	fillResults();
}

double State::convertToPercent(int partialVote)
{
	return (double)(partialVote * 100) / allVotes;
}

void State::fillResults()
{
	for(int i = 0; i < numberOfParies; ++i)
	{
		finalResults.push_back(make_pair(partiesNames[i], convertToPercent(partialVotes[i])));
	}
}

void State::printResults()
{
	for(auto &it : finalResults)
	{
		cout  <<  setw(5)  <<  it.first << "   " << setprecision(3) << it.second << "%" <<endl;
	}
}

void State::sortResultsByName()
{
	sort(finalResults.begin(), finalResults.end());
}

void State::sortResultsByPercent()
{
	auto cmp = [](pair<string,double> const & a, pair<string,double> const & b)
	{
		 return a.second != b.second?  a.second > b.second : a.first < b.first;
	};

	sort(finalResults.begin(), finalResults.end(), cmp);
}

State::~State()
{
	// TODO Auto-generated destructor stub
}


