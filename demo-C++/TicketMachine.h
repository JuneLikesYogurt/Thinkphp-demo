
#ifndef TICKETMACHINE_H_
/*  如果已经定义了中间的部分，则中间部分不编译*/
#define TICKETMACHINE_H_

class TicketMachine {
    public:
        TicketMachine();
        virtual ~TicketMachine();
        void showPrompt();
        void insertMoney(int money);
        void showBalance();
        void printTicket();
        void showTotal();
    private:
        const int PRICE;
        int balance;
        int total;
}
/*                */
#endif