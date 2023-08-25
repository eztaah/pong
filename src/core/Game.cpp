#include "globals.hpp"
#include "Game.hpp"
#include "MenuState.hpp"
#include "PlayingState.hpp"
#include "GameOverState.hpp"


///////////////// PUBLIC /////////////////
Game::Game()
    : _currentState(std::make_unique<MenuState>(this)),
      _score(0)
{
    // Setup current game state
    _currentState->OnEnter();
}

void Game::Update()
{
    _currentState->Update();
}

void Game::Render()
{
    rl::BeginDrawing();
    rl::ClearBackground(rl::BLACK);

    // Set up the drawing area
    rl::BeginScissorMode(MARGIN_X, MARGIN_Y, GAME_WIDTH, GAME_HEIGHT);
    rl::ClearBackground(rl::RAYWHITE);  // Fill the game area with green

    _currentState->Render();

    rl::EndScissorMode();
    rl::EndDrawing();
}

void Game::Reset()
{
    _ChangeState(std::make_unique<MenuState>(this));     // permet à game de passer sa propre instance à MenuState
}

void Game::MenuGame() {
    _ChangeState(std::make_unique<MenuState>(this));
}

void Game::StartGame() {
    _ChangeState(std::make_unique<PlayingState>(this));     // Le constructeur de la classe playing state à besoin d'un pointeur vers l'instance de la classe game
}

void Game::EndGame() {
    _ChangeState(std::make_unique<GameOverState>(this));
}

unsigned int Game::GetScore() const {
    return _score;
}

void Game::IncreaseScore() {
    _score++;
}

void Game::ResetScore() {
    _score = 0;
}




///////////////// PRIVATE /////////////////
void Game::_ChangeState(std::unique_ptr<GameState> newState)
{
    if(_currentState)   // If the pointer exists
        _currentState->OnExit();    // Execute the exit logic related to the current state

    _currentState = std::move(newState);    // Change the state of the game
    _currentState->OnEnter();   // Execute the enter logic related to the new state
}