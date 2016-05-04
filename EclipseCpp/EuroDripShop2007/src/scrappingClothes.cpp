
#include "scrappingClothes.h"


scrappingClothes::scrappingClothes(int scrapClothes)
{
	setScrappingClothes(scrapClothes);
}



int scrappingClothes::getScrappingClothes() const {
	return scrapClothes;
}

void scrappingClothes::setScrappingClothes(int scrapClothes)
{
	if(scrapClothes > 0)
	{
		this->scrapClothes = scrapClothes;
	}
	else
	{
		scrapClothes = 0;
	}
}

scrappingClothes::~scrappingClothes()
{

}
