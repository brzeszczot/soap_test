#include <iostream>
#include "soapH.h" // obtain the generated stub 
#include "MbsLookupSoapBinding.nsmap" // obtain the generated XML namespace mapping table for the Quote service 
main() 
{ 
   std::cout<<"Content-type: text/html"<<std::endl<<std::endl;
   std::cout<<"<html><body>"<<std::endl;
   
   struct soap *soap = soap_new();
   struct ns5__findStoresResponse quote; 
   if (soap_call_ns5__findStores(soap, NULL, NULL, "12345", quote) == SOAP_OK) 
   {
   		std::cout << quote._findStoresReturn->__size << std::endl;
		for(int ii=0;ii<quote._findStoresReturn->__size;ii++)
		{
   			std::cout << *quote._findStoresReturn->__ptr[ii]->distance << std::endl;
   			std::cout << *quote._findStoresReturn->__ptr[ii]->store->storeName << std::endl;
   			std::cout << *quote._findStoresReturn->__ptr[ii]->store->storeId << std::endl;
			std::cout << std::endl;
   		}
   	}
	//else // an error occurred 
   //   soap_print_fault(soap, stderr); // display the SOAP fault on the stderr stream 
}
