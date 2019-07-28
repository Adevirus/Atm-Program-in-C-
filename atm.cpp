#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class personnel
{
    private:
        int AccBal;
        int AcctNumList[50] = {156812, 168902};
        string Title; //Title
        string FName; //First Name
        string surName; //Surname
        string oNames; //Other Names
        string marSta; //Marital Status
        long int AcctNumber; //Account Number
        string AcctName; //Account Name
        short int pinNum; //Pin Number
        string tel; //telephone Number
        string address; //address
        string DOB; //date of birth
        string AcctType; //account type
        string recipientbank; //recipient bank
        string recepientaccnum; //recipient account number
        int moneytransferred; //Amount Transferred
        int moneysave;
            string saveactnam;
            string Branch;
            string DepName;
            string DepTel;
            int amountsaved;
            string amountinwords;
            int actnum;
    public:
        string reply;
        int WelcomeTxt()
        {
            cout<<"======================================================================================="<<endl;
            cout<<"=============================Welcome to First Bank Nigeria PLC========================="<<endl;
            cout<<"=======================================================================================\n"<<endl;
            cout<<"Do you have an account?: \t";
            cin>>reply;
            if(reply == "Yes" || reply == "YES" || reply == "yes" || reply == "y" || reply == "Y")
            {
                return 1;
            }else if(reply == "No" || reply == "NO" || reply == "no" || reply == "N" || reply == "n")
            {
                return 0;
            }
        }
        void createAcct()
        {
            cout<<"\n\n--------------------------------------------------";
            cout<<"\n->This Form should Be Written in CAPITAL LETTERS<-\n";
            cout<<"--------------------------------------------------\n\n\n";

            cout<<"-------------------------------------------------------------------------\n";
            cout<<"--------------------------PERSONAL INFORMATION---------------------------\n";
            cout<<"-------------------------------------------------------------------------\n\n";
            cout<<"Title: ";
            cin>>Title;
            cout<<"First Name: \t";
            cin>>FName;
            cout<<"Surname: \t";
            cin>>surName;
            cout<<"Other Names: \t";
            cin>>oNames;
            cout<<"Enter Your Telephone Number: \t";
            cin>>tel;
            cout<<"Enter Your House Address: \t";
            cin>>address;
            cout<<"Enter Your Date of Birth: \t";
            cin>>DOB;

            cout<<"Marital Status[Single or Married if Others specify]:\t";
            cin>>marSta;

            cout<<"\n\n-------------------------------------------------------------------------\n";
            cout<<"-----------------------------ACCOUNT DETAILS-----------------------------\n";
            cout<<"-------------------------------------------------------------------------\n\n";

            cout<<"\n\n--------------------------------------------------------------";
            cout<<"\n->Note Your Account Number would Be generated after the form<-\n";
            cout<<"--------------------------------------------------------------\n\n\n";

            cout<<"->Information Containing Space put Underscore '_'<-\n\n\n";
            cout<<"Pick Account Type [Savings Current or Fixed-Deposit]:\t ";
            cin>>AcctType;
            cout<<"Pick Account Name:\t ";
            cin>>AcctName;
            cout<<"Pick Account Pin Number:\t ";
            cin>>pinNum;
            cout<<"\n                                ------------\n";
            cout<<"Your Account Number is: \t"<<"->>"<<AcctNumList[0]<<"<<-\n";
            cout<<"                                ------------\n";
            recordDetails();
        }

        void recordDetails()
        {
            string filename = "Candidate "+ FName + ".txt";
            ofstream file;
            file.open(filename.c_str());
            file<<"----------------------------------------------------------\n";
            file<<"-----------------Candidate Info (Not Updated)-------------\n";
            file<<"----------------------------------------------------------\n\n";

            file<<"------------------->PERSONAL INFORMATION<-----------------"<<endl;
            file<<"Title: "<<Title<<endl;
            file<<"First Name: "<<FName<<endl;
            file<<"SurName/LastName: "<<surName<<endl;
            file<<"Other Name: "<<oNames<<endl;
            file<<"Telephone: "<<tel<<endl;
            file<<"Address: "<<address<<endl;
            file<<"Date of Birth: "<<DOB<<endl;

            file<<"\n----------------->ACCOUNT INFORMATION<------------------"<<endl;
            file<<"Account Name: "<<AcctName<<endl;
            file<<"Account Type: "<<AcctType<<endl;
            file<<"Pin Number: "<<pinNum<<endl;
            file<<"Account Number: "<<AcctNumList[0]<<endl;
            file<<"----------------------------------------------------------";
            file.close();
        }
        int CheckPin(int pinNum)
        {
            cout<<"\n\nValidating Pin..............\n";
            int pinList[] = {1234, 1236, 1237, 2004};
            if(pinNum == pinList[0] || pinNum == pinList[1] || pinNum == pinList[2] || pinNum == pinList[3])
            {
                return 1;
            }else{
             return 0;
            }
        }
        void getinfo(int pin)
        {
            if(pin == 1234)
            {
                Title = "Mr.";
                FName = "Rehoboth";
                surName = "Micah-Daniels";
                AcctType = "Savings";
                AcctNumber = 56776;
                pinNum = 1234;
                tel = "07030700028";
                AcctName = "Micah-Daniels_Rehoboth";
                AccBal = 0;
            }else if(pin == 2004)
            {
                Title = "Mr.";
                FName = "Tomiwa";
                surName = "Amole";
                AcctType = "Savings";
                AcctNumber = 56712;
                pinNum = 2004;
                tel = "09092354394";
                AcctName = "Tomiwamole";
                AccBal = 0;
            }else if(pin == 1236)
            {
                Title = "Mrs.";
                FName = "Seun";
                surName = "Amole";
                AcctType = "Fixed-Deposit";
                AcctNumber = 56743;
                pinNum = 1236;
                tel = "07030703228";
                AcctName = "Seun_Amole";
                AccBal = 0;
            }else if(pin == 1237)
            {
                Title = "Mr.";
                FName = "Prince";
                surName = "Daniel";
                AcctType = "Current";
                AcctNumber = 56787;
                pinNum = 1237;
                tel = "07034320028";
                AcctName = "Prince_Daniel";
                AccBal = 0;
            }
        }
        int ReQuestPin(){
            int pin;
            cout<<"\n\n-----------------------------\n";
            cout<<"---------PIN RECIEPT---------\n";
            cout<<"-----------------------------\n";
            cout<<"Enter Your Pin: ";
            cin>>pin;

            return pin;
        }
        int transactionAsk(){
            int reply;
            int checkres;
            int pin;
            static int pincalls = 0;
            static int functioncalls = 0;
            cout<<"\n\n--------------------------------------------\n";
            cout<<"----------------Transaction-----------------\n";
            cout<<"--------------------------------------------\n\n";
            cout<<"----------------------------\n";
            cout<<"Pick Transaction to perform: \n";
            cout<<"----------------------------\n";
            cout<<"-->Note: For Specific Transaction you should have money in bank\n";
            cout<<"->1. Change Mobile Number \t->2. Change Pin \n->3. Retrieve Bank info";
            cout<<"\t\t->4. Check Account Balance \n->5. Transfer Funds \t\t->6. Pay Bills\n->7. Withdraw Funds";
            cout<<"\t\t->8. Print Account Statement \n->9. Save Money";
            cout<<"\n\nReply>>> ";
            cin>>reply;


             pin = ReQuestPin();
            checkres = CheckPin(pin);
            if(functioncalls == 0)
            {
                getinfo(pin);
                ++functioncalls;
            }
            if(reply == 1 && checkres == 1)
            {
                cout<<"\n-->Pin Available.<--\n";
                //getinfo(pin);
                return reply;
            }else if(reply == 2 && checkres == 1)
            {
                cout<<"\n-->Pin Available.<--\n";
                //getinfo(pin);
                return reply;
            }else if(reply == 3 && checkres == 1)
            {
                cout<<"\n-->Pin Available.<--\n";
                //getinfo(pin);
                return reply;
            }
            else if(reply == 4 && checkres == 1)
            {
                cout<<"\n-->Pin Available.<--\n";
                //getinfo(pin);
                return reply;
            }else if(reply == 5 && checkres == 1)
            {
                cout<<"\n-->Pin Available.<--\n";
                //getinfo(pin);
                return reply;
            }else if(reply == 6 && checkres == 1)
            {
                cout<<"\n-->Pin Available.<--\n";
                //getinfo(pin);
                return reply;
            }else if(reply == 7 && checkres == 1)
            {
                cout<<"\n-->Pin Available.<--\n";
                //getinfo(pin);
                return reply;
            }else if(reply == 8 && checkres == 1)
            {
                cout<<"\n-->Pin Available.<--\n";
                //getinfo(pin);
                return reply;
            }else if(reply == 9 && checkres == 1)
            {
                cout<<"\n-->Pin Available.<--\n";
                //getinfo(pin);
                return reply;
            }else{
                cout<<"\nInvalid Input or Wrong Pin.";
            }

        }
        int ChangeMobileNum()
        {
            string NMobilNum;
            cout<<"\n\n--------------------------------------------\n";
            cout<<"--------------CHANGE MOBILE NUMBER----------\n";
            cout<<"--------------------------------------------\n\n";
            string rep;
            cout<<"Hello "<<Title<<" "<<FName<<" "<<surName<<endl;
            cout<<"Your Current Telephone Number is: "<<tel<<endl;

            cout<<"\n->"<<tel<<"<-\n";
            cout<<"Enter New Mobile Number: ->";
            cin>>NMobilNum;
            tel = NMobilNum;
            cout<<"\nYour New Mobile Number is: "<<tel;
            cout<<"\n\nDo You want to perform another transaction:  ";
            cin>>rep;
            if(rep == "Y" || rep =="YES" || rep == "y" || rep == "yes"){
                return 1;
            }else if(rep == "No" || rep == "N" || rep =="n" || rep =="NO" || rep == "no"){
                return 0;
            }
        }
        int ChangePin()
        {
            short int pin;
            cout<<"\n\n----------------------------------------------\n";
            cout<<"----------------CHANGE PIN NUMBER-------------\n";
            cout<<"----------------------------------------------\n";
            string rep;
            cout<<"Hello "<<Title<<" "<<FName<<" "<<surName<<endl;
            cout<<"Your Current Pin Number is: "<<pinNum<<endl;

            cout<<"\n->"<<pinNum<<"<-\n";
            cout<<"Enter New Pin Number: ->";
            cin>>pin;
            pinNum = pin;
            cout<<"\nYour New Pin Number is: "<<pinNum;
            cout<<"\n\nDo You want to perform another transaction:  ";
            cin>>rep;
            if(rep == "Y" || rep =="YES" || rep == "y" || rep == "yes"){
                return 1;
            }else if(rep == "No" || rep == "N" || rep =="n" || rep =="NO" || rep == "no"){
                return 0;
            }
        }
        int RetrieveBankinfo()
        {
            cout<<"\n\n----------------------------------------------\n";
            cout<<"----------------RETRIEVE BANK INFO-------------\n";
            cout<<"----------------------------------------------\n";
            string rep;
            cout<<"\nAccessing Database........\n";
            cout<<"\nChecking Database........\n";
            cout<<"\nRetrieving Bank Info........\n";
            cout<<"---------------------------------------"<<endl;
            cout<<"---------------->Info<-----------------"<<endl;
            cout<<"---------------------------------------"<<endl;
            cout<<"\nAccount Name: "<<AcctName;
            cout<<"\nAccount Number: "<<AcctNumber;
            cout<<"\nAccount Type: "<<AcctType;
            cout<<"\nPin Number:  "<<pinNum;
            cout<<"\nTelephone Number: "<<tel;
            cout<<"\nAccount Balance: "<<AccBal;
            cout<<"\n----------------------------------------"<<endl;
            cout<<"\n\nDo You want to perform another transaction:  ";
            cin>>rep;
            if(rep == "Y" || rep =="YES" || rep == "y" || rep == "yes"){
                return 1;
            }else if(rep == "No" || rep == "N" || rep =="n" || rep =="NO" || rep == "no"){
                return 0;
            }
        }
        int CheckAcctBal()
        {
            cout<<"\n\n----------------------------------------------\n";
            cout<<"----------------CHECK ACCOUNT BALANCE---------\n";
            cout<<"----------------------------------------------\n\n";

            string rep;
            cout<<"Hello "<<Title<<" "<<FName<<" "<<surName<<endl;
            cout<<"Your Current Account Balance is: #"<<AccBal<<endl;

            cout<<"\n-----------------------------------------------"<<endl;
            cout<<"\n\nDo You want to perform another transaction:  ";
            cin>>rep;
            if(rep == "Y" || rep =="YES" || rep == "y" || rep == "yes"){
                return 1;
            }else if(rep == "No" || rep == "N" || rep =="n" || rep =="NO" || rep == "no"){
                return 0;
            }
        }
        int TransferFunds()
        {
            int rep;
            string reply;
            cout<<"\n\n----------------------------------------------\n";
            cout<<"-------------------TRANSFER FUNDS------------\n";
            cout<<"----------------------------------------------\n\n";
            cout<<"Hello "<<Title<<" "<<FName<<" "<<surName<<endl;
            cout<<"-->Pick Bank<--"<<endl;
            cout<<"1.First Bank\t2.Fidelty Bank\t3.Access Bank\n";
            cout<<"4.Zenith Bank\t5.Rehoboth Bank\t6.UBA\n";
            cout<<"7.GTB(Guarantee Trust Bank)\n";
            cout<<"8.FCMB(First City Monument Bank)\n";
            cout<<"\nReply>>> ";
            cin>>rep;

            switch(rep)
            {
            case 1:
                recipientbank = "First Bank";
                break;
            case 2:
                recipientbank = "Fidelty Bank";
                break;
            case 3:
                recipientbank = "Access Bank";
                break;
            case 4:
                recipientbank = "Zenith Bank";
                break;
            case 5:
                recipientbank = "Rehoboth Bank";
                break;
            case 6:
                recipientbank = "UBA";
                break;
            case 7:
                recipientbank = "GTB(Guarantee Trust Bank)";
                break;
            case 8:
                recipientbank = "FCMB(First City Monument Bank)";
                break;
            }
            cout<<"\nEnter Recipient Account Number: ";
            cin>>recepientaccnum;
            do
            {

            cout<<"Enter Transfer Amount: #";
            cin>>moneytransferred;

            if(AccBal < moneytransferred)
            {
                cout<<"You Do Not Have Enough Cash to perform the transaction."<<endl;
                cout<<"Your Account Balance is just."<<AccBal<<endl;
            }
            }while((AccBal < moneytransferred));
            cout<<"\nDo you want to proceed with Transaction? "<<endl;
            cin>>reply;


            if(reply == "Y" || reply =="YES" || reply == "y" || reply == "yes"){
                cout<<"You Have successfully transferred #"<<moneytransferred<<" to "<<recepientaccnum<<endl;
                AccBal-=moneytransferred;
            }else if(reply == "No" || reply == "N" || reply =="n" || reply =="NO" || reply == "no"){
                cout<<"Transaction Stopped...."<<endl;
            }
                cout<<"\n-----------------------------------------------"<<endl;
            cout<<"\n\nDo You want to perform another transaction:  ";
            cin>>reply;
            if(reply == "Y" || reply =="YES" || reply == "y" || reply == "yes"){
                return 1;
            }else if(reply == "No" || reply == "N" || reply =="n" || reply =="NO" || reply == "no"){
                return 0;
            }

        }
        int PayBills()
        {
            string rep;
            string payrep;
            cout<<"\n\n----------------------------------------------\n";
            cout<<"-------------------PAY BILLS------------------\n";
            cout<<"----------------------------------------------\n\n";
            cout<<"Hello "<<Title<<" "<<FName<<" "<<surName<<endl;
            cout<<"\n----------------------\n";
            cout<<"------BILL INFO-------\n";
            cout<<"----------------------\n";
            cout<<"Electricity Bill: #500"<<endl;
            cout<<"Water Bill: #500"<<endl;
            cout<<"Tax Payment: #500"<<endl;
            cout<<"Mortgage: #500"<<endl;
            cout<<"\nTotal is #2000"<<endl;
            cout<<"---------------------------\n"<<endl;
            cout<<"Do you want to proceed with payment: ";
            cin>>payrep;
            if(payrep == "Y" || payrep == "YES" || payrep == "y" || payrep == "yes")
            {
                AccBal -=20000;
                cout<<"\nBill of #2000 Has been paid and deducted from your account";
            }else if(payrep == "N" || payrep == "NO" || payrep == "No" || payrep == "no")
            {
                cout<<"\nTransaction Stopped.";
            }
            cout<<"\n-----------------------------------------------"<<endl;
            cout<<"\n\nDo You want to perform another transaction:  ";
            cin>>rep;
            if(rep == "Y" || rep =="YES" || rep == "y" || rep == "yes"){
                return 1;
            }else if(rep == "No" || rep == "N" || rep =="n" || rep =="NO" || rep == "no"){
                return 0;
            }
        }

        int WithdrawFunds()
        {
            string rep;
            int withdrawrep;
            int specwithdrawrep;
            cout<<"\n\n----------------------------------------------\n";
            cout<<"----------------WITHDRAW FUNDS----------------\n";
            cout<<"----------------------------------------------\n\n";
            cout<<"Hello "<<Title<<" "<<FName<<" "<<surName<<endl;
            cout<<"Select How much you want to withdraw"<<endl;
            cout<<"1.#1,000\t2.2,000"<<endl;
            cout<<"3.#5,000\t4.10,000"<<endl;
            cout<<"5.#20,000\t6.40,000"<<endl;
            cout<<"7.Other"<<endl;
            cout<<"Reply>>> ";
            cin>>withdrawrep;

            if(withdrawrep == 1)
            {
                if(AccBal > 1000){
                    AccBal-=1000;
                    cout<<"\nTake your Money"<<endl;
                }else if(AccBal < 1000){
                    cout<<"\nYou Do not Have Enough Resources"<<endl;
                    cout<<"Your Account Balance is just "<<AccBal;
                }
            }else if(withdrawrep == 2)
            {
                if(AccBal > 2000){
                    AccBal-=2000;
                    cout<<"\nTake your Money"<<endl;
                }else if(AccBal < 2000){
                    cout<<"\nYou Do not Have Enough Resources"<<endl;
                    cout<<"Your Account Balance is just "<<AccBal;
                }
            }else if(withdrawrep == 3)
            {
                if(AccBal > 5000){
                    AccBal-=5000;
                    cout<<"\nTake your Money"<<endl;
                }else if(AccBal < 5000){
                    cout<<"\nYou Do not Have Enough Resources"<<endl;
                    cout<<"Your Account Balance is just "<<AccBal;
                }
            }else if(withdrawrep == 4)
            {
                if(AccBal > 10000){
                    AccBal-=10000;
                    cout<<"\nTake your Money"<<endl;
                }else if(AccBal < 10000){
                    cout<<"\nYou Do not Have Enough Resources"<<endl;
                    cout<<"Your Account Balance is just "<<AccBal;
                }
            }else if(withdrawrep == 5)
            {
                if(AccBal > 20000){
                    AccBal-=20000;
                    cout<<"\nTake your Money"<<endl;
                }else if(AccBal < 20000){
                    cout<<"\nYou Do not Have Enough Resources"<<endl;
                    cout<<"Your Account Balance is just "<<AccBal;
                }
            }else if(withdrawrep == 6)
            {
                if(AccBal > 40000){
                    AccBal-=40000;
                    cout<<"\nTake your Money"<<endl;
                }else if(AccBal < 40000){
                    cout<<"\nYou Do not Have Enough Resources"<<endl;
                    cout<<"Your Account Balance is just "<<AccBal;
                }
            }else if(withdrawrep == 7)
            {
                cout<<"\nSpecify: ";
                cin>>specwithdrawrep;
                if(AccBal > specwithdrawrep){
                    AccBal-=specwithdrawrep;
                    cout<<"\nTake your Money"<<endl;
                }else if(AccBal < specwithdrawrep){
                    cout<<"\nYou Do not Have Enough Resources"<<endl;
                    cout<<"Your Account Balance is just "<<AccBal;
                }
            }
            cout<<"\n-----------------------------------------------"<<endl;
            cout<<"Do You want to perform another transaction:  ";
            cin>>rep;
            if(rep == "Y" || rep =="YES" || rep == "y" || rep == "yes"){
                return 1;
            }else if(rep == "No" || rep == "N" || rep =="n" || rep =="NO" || rep == "no"){
                return 0;
            }
        }
        int PrintAccountStatement()
        {

        }
        int SaveMoney()
        {
            string rep;

                cout<<"\n\n----------------------------------------------\n";
            cout<<"-------------------SAVE MONEY-----------------\n";
            cout<<"----------------------------------------------\n\n";
            cout<<"Hello "<<Title<<" "<<FName<<" "<<surName<<endl;
            do
            {

            cout<<"Enter Account Name: ";
            cin>>saveactnam;
            if(saveactnam == "Micah-Daniels_Rehoboth" || saveactnam == "Tomiwa_Amole" || saveactnam == "Seun_Amole" || saveactnam == "Prince_Daniel")
            {

            }else{
                cout<<"-->Your Account Name does not exist<--"<<endl;
            }

            }while(!(saveactnam == "Micah-Daniels_Rehoboth" || saveactnam == "Tomiwa_Amole" || saveactnam == "Seun_Amole" || saveactnam == "Prince_Daniel"));
            do
            {

            cout<<"Enter Account Number: ";
            cin>>actnum;
            if(saveactnam == "Micah-Daniels_Rehoboth" && actnum == 56776|| saveactnam == "Tomiwa_Amole" && actnum == 56712||
               saveactnam == "Seun_Amole" && actnum == 56743|| saveactnam == "Prince_Daniel" && actnum == 56787)
            {

            }else{
                cout<<"-->Your Account Number does not match Account Name<--"<<endl;
            }
            }while(!(saveactnam == "Micah-Daniels_Rehoboth" && actnum == 56776|| saveactnam == "Tomiwa_Amole" && actnum == 56712||
               saveactnam == "Seun_Amole" && actnum == 56743|| saveactnam == "Prince_Daniel" && actnum == 56787));
            cout<<"Enter BRANCH: ";
            cin>>Branch;
            cout<<"Enter Depositors Name: ";
            cin>>DepName;
            cout<<"Enter Depositors Telephone Number: ";
            cin>>DepTel;
            cout<<"Enter Amount on figures: #";
            cin>>amountsaved;
            cout<<"Enter Amount in words: ";
            cin>>amountinwords;

            cout<<"\n\nTransfer #"<<amountsaved<<" to "<<saveactnam;
            cout<<"\n\nDo You Want to proceed Transaction?.."<<endl;
            cout<<"Reply>>> ";
            cin>>rep;
            if(rep == "Y" || rep =="YES" || rep == "y" || rep == "yes"){
                cout<<"\nYou Have successfully paid #"<<amountsaved<<" to "<<saveactnam;
                if(saveactnam == AcctName)
                {
                    AccBal = amountsaved;
                }
            }else if(rep == "No" || rep == "N" || rep =="n" || rep =="NO" || rep == "no"){
                cout<<"Transaction Stopped";
            }
            cout<<"\n\n-----------------------------------------------------------------"<<endl;
            cout<<"\n\nDo You want to perform another transaction:  ";
            cin>>rep;
            if(rep == "Y" || rep =="YES" || rep == "y" || rep == "yes"){
                return 1;
            }else if(rep == "No" || rep == "N" || rep =="n" || rep =="NO" || rep == "no"){
                return 0;
            }

        }
        void endProgram()
        {
            cout<<"\n=======================================================================\n";
            cout<<"====================Thank You For Banking With US======================\n";
            cout<<"=======================================================================\n";
        }
};
main()
{
    int AcctPres;
    int transac;
    personnel p1;
    AcctPres = p1.WelcomeTxt();
    int transaccont;
    label:{
    if(AcctPres == 1){
        transac = p1.transactionAsk();
    }else if(AcctPres == 0){
        p1.createAcct();
    }



    switch(transac){
    case 1:
        transaccont = p1.ChangeMobileNum();
        break;
    case 2:
        transaccont = p1.ChangePin();
        break;
    case 3:
        transaccont = p1.RetrieveBankinfo();
        break;
     case 4:
        transaccont = p1.CheckAcctBal();
        break;
    case 5:
        transaccont = p1.TransferFunds();
        break;
    case 6:
        transaccont = p1.PayBills();
        break;
    case 7:
        transaccont = p1.WithdrawFunds();
        break;
    case 8:
        transaccont = p1.PrintAccountStatement();
        break;
    case 9:
        transaccont = p1.SaveMoney();
        break;
    }

    }

    if (transaccont == 1)
    {
        goto label;
    }else
    {
        p1.endProgram();
    }
}
