package oop.ex;

public class Account {
    int balance;

    void deposit(int amount) {
        balance += amount;
    }

    void withdrow(int amount){
        if (amount > balance) {
            System.out.println("잔액이 부족합니다");
        }
        else
            balance -= amount;
    }

    void condition(){
        System.out.println("잔액 : "+ balance);
    }
}
