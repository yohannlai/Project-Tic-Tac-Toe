#include "../include/Player.hpp"

// Crée un joueur en demandant son nom et symbole
Player create_player(){
    Player player;
    std::cout << "Entrer le nom du joueur: ";
    std::cin >> player.name;

    // Demande un symbole valide (X ou O)
    do{
        std::cout << "Choisissez un symbole (X ou O): ";
        std::cin >> player.symbol;
        
        if(player.symbol != 'X' && player.symbol != 'O' || std::cin.fail())
        {
            std::cin.clear(); // Réinitialise l'état de l'entrée
            std::cin.ignore(255, '\n'); // Ignore les caractères restants
            std::cout << "Entrée invalide. On a dit X ou O ! ";
        }
    } while (player.symbol != 'X' && player.symbol != 'O' || std::cin.fail());

    return player;
}
