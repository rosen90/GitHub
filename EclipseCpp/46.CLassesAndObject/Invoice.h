#ifndef INVOICE_H_
#define INVOICE_H_


#endif /* INVOICE_H_ */

#include <string>

using namespace std;

class Invoice
{
	private:
		int partNumber;
		string partDescription;
		int quantity;
		float pricePerItem;

	public:

		Invoice (int partNum, string partDes, int partQuantity, float ItemPrice)
		{
			setPartNumber(partNum);
			setPartDescription(partDes);
			setPartQuantity(partQuantity);
			setPricePerItem(ItemPrice);
		}

		void setPartNumber(int number)
		{
			if (number >= 0)
			{
				partNumber = number;
			}

		}

		int getPartNumber()
		{
			return partNumber;
		}

		void setPartDescription(string description)
		{
			partDescription = description;
		}

		string getPartDescription()
		{
			return partDescription;
		}

		void setPartQuantity(int quantityCount)
		{
			if(quantityCount > 0)
			{
				quantity = quantityCount;
			}
			else
			{
				quantity = 0;
			}
		}

		int getPartQuantity()
		{
			return quantity;
		}

		void setPricePerItem(float price)
		{
			if (price > 0)
			{
				pricePerItem = price;
			}
			else
			{
				pricePerItem = 0;
			}
		}

		float getPricePerItem()
		{
			return pricePerItem;
		}



		int getInvoiceAmount()
		{

			return quantity * pricePerItem;
		}
};
