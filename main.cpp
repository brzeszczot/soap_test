#include <iostream>
#include <string>
#include "soapH.h" // obtain the generated stub
#include "SoapSoap.nsmap" // obtain the generated XML namespace mapping table for the Quote service
//#include "httpda.h"

// wsdl2h -o test.hpp http://brzeszczot.net/open/php-wsdl-2.3/demo.php?WSDL
// soapcpp2 test.hpp
// g++ -Wall -o main main.c soapC.cpp soapClient.cpp -lgsoap++

const char* userid = "dupa";
const char* passwd = "dupa";

int main(int argc, char **argv)
{
    //std::cout<<"Content-type: text/html"<<std::endl<<std::endl;
    //std::cout<<"<html><body>"<<std::endl;

    struct soap* soap = soap_new();
    soap->userid = userid;
    soap->passwd = passwd;

    ns1__AccountAuthResponse output;
    std::string email("brzeszczot@gmail.com");
    std::string pass("alamakota");

//    soap_register_plugin(soap, http_da);
    if(soap_call_ns1__AccountAuth(soap, NULL, NULL, email, pass, output) == SOAP_OK)
    {
        std::cout << "========================" << std::endl;
            for(int ii = 0; ii < output._return_->__size; ii++)
                std::cout << output._return_->__ptr[ii] << std::endl;
        std::cout << "========================" << std::endl;
    }

    soap_end(soap);
    soap = soap_new();
    soap->userid = userid;
    soap->passwd = passwd;

    ns1__GetWordResponse output2;
    std::string range("ALL");
    stringArray* opt = new stringArray;
    opt->__ptr = new std::string[3];
    opt->__size = 3;
    opt->__ptr[0] = "Ala ";
    opt->__ptr[1] = "ma ";
    opt->__ptr[2] = "kota! :)";

    if(soap_call_ns1__GetWord(soap, NULL, NULL, range, opt, output2) == SOAP_OK)
    {
        std::cout << "========================" << std::endl;
            for(int ii = 0; ii < output2._return_->__size; ii++)
                std::cout << output2._return_->__ptr[ii] << std::endl;
        std::cout << "========================" << std::endl;
    }

    return 0;

	//else // an error occurred
   //   soap_print_fault(soap, stderr); // display the SOAP fault on the stderr stream
}
