/*
 * Copyright 2017-2018, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *      * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *      * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *
 *      * Neither the name of the copyright holder nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef OBJCPP_EXAMPLES_PMPONG_PONGGAMESTATUS_HPP
#define OBJCPP_EXAMPLES_PMPONG_PONGGAMESTATUS_HPP
#include "Ball.hpp"
#include "GameConstants.hpp"
#include "Paddle.hpp"
#include <SFML/Graphics.hpp>
#include <libpmemobj++/p.hpp>
#include <libpmemobj++/persistent_ptr.hpp>
#include <libpmemobj++/transaction.hpp>

enum game_state { MATCH, MENU, GAME_OVER, SIMULATE };

class PongGameStatus {
public:
	PongGameStatus();
	~PongGameStatus();

	void startBall(float ballSpeed);
	void reset();
	void movePaddles();
	void lookForCollisions(bool increaseBallVelocity);
	void actualizeStatus();
	void simulate();
	void setMenuItem(int numb);
	void setIsGameToResume(bool isGameToRes);
	void setGameState(game_state state);

	int getMenuItem();

	float randomizeFloatValue(float min, float max);

	bool score();
	bool checkIfAnyPlayerWon();
	bool randomizeDirection();
	bool getIsGameToResume();

	pmem::obj::persistent_ptr<Paddle> getPlayer1();
	pmem::obj::persistent_ptr<Paddle> getPlayer2();
	pmem::obj::persistent_ptr<Ball> getBall();

	game_state getGameState();

private:
	pmem::obj::persistent_ptr<Paddle> player1;
	pmem::obj::persistent_ptr<Paddle> player2;
	pmem::obj::persistent_ptr<Ball> ball;

	pmem::obj::p<int> menuItem;
	pmem::obj::p<bool> isGameToResume;
	pmem::obj::p<game_state> actualGameState;
};
#endif /* OBJCPP_EXAMPLES_PMPONG_PONGGAMESTATUS_HPP */
