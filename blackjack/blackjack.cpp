// blackjack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

int main()
{
    // rand function
    srand(time(0));
    // variables
    char choice;
    int dealer_hand = 0;
    int player_hand = 0;
    int randNum = 0;
    dealer_hand += randNum = 1 + (rand() % 10);
    // opening welcome text
    std::cout << "Welcome to Blackjack!\nAre you ready to play? (Y/N)";
    std::cin >> choice;
    // if user input y then will begin play
    if (choice == 'y' || choice == 'Y') {
            // draws card for player and dealer with random numbers
            for (int i = 0; i < 2; i++) {
                player_hand += randNum = 1 + (rand() % 10);
            }
            std::cout << "Dealer Has: " << dealer_hand << "\n";
            std::cout << "You Have: " << player_hand << "\n";

        // asks user for their choice to hit or stand
        std::cout << "\nWould you like to hit or stand? (H/S)";
        std::cin >> choice;
        // if user chooses to hit...
        while (choice == 'H' || choice == 'h') {
            // adds random int from 1-10 into players current hand
            player_hand += randNum = 1 + (rand() % 10);
            std::cout << "You drew a: " << randNum;
            std::cout << "\nYou have: " << player_hand;
            if (player_hand > 21) {
                std::cout << "\nOh no.. You went over with: " << player_hand << " You bust!";
                exit(0);
            }
            else if (player_hand == 21) {
                std::cout << "\nyou got blackjack: " << player_hand;
                break;
            }
            std::cout << "\nWould you like to hit again? (H/S)";
            std::cin >> choice;
            // if user chooses to stand then it will leave while loop
            if (choice == 'S' || choice == 's') {
                break;
            }
        }
        // Dealer pulls cards up to 16
        while (dealer_hand) {

            // adds random int from 1 - 10 into dealer hand
            dealer_hand += randNum = 1 + (rand() % 10);
            std::cout << "\nDealer draws a: " << randNum;
            std::cout << "\nDealer has: " << dealer_hand;
            Sleep(1000);

            if (dealer_hand == 21) {
                std::cout << "\nDealer has: " << dealer_hand << " Dealer blackjack!";
                break;
            }
            else if (dealer_hand > 21) {
                std::cout << "\nDealer has: " << dealer_hand << " Dealer bust!";
                break;
            }
            else if (dealer_hand > 16) {
                std::cout << "\nDealer has: " << dealer_hand;
                break;
            }
        }
            // displays winner then exits program
            if (dealer_hand > player_hand) {
                std::cout << "\nDealer wins with: " << dealer_hand << "\nYou had: " << player_hand;
                exit(0);
            }
            if (player_hand > dealer_hand) {
                std::cout << "\nYou win with: " << player_hand << "\nDealer had: " << dealer_hand;
                exit(0);
            }
            if (player_hand == dealer_hand) {
                std::cout << "\nYou push with: " << player_hand << "\nDealer had: " << dealer_hand;
                exit(0);
            }
    }
    //if user chooses not to play then program exits
    else {
        exit(0);
    }
}