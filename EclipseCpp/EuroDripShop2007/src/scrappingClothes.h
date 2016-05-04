#ifndef SCRAPPINGCLOTHES_H_
#define SCRAPPINGCLOTHES_H_

class scrappingClothes
{
public:
	scrappingClothes(int = 0);
	virtual ~scrappingClothes();
	int getScrappingClothes() const;
	void setScrappingClothes(int scrapClothes);

private:
	int scrapClothes;
};

#endif
