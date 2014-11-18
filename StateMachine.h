#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <inttypes.h>

#define E_ANY -1
#define NULL 0

// Header
class State;
class Transition;

// Impementations
class State{
public:
  State(uint8_t id, void (* entryAction) (), Transition * transitions);
  Transition * findTransition(uint8_t e);
  uint8_t id;
private:
protected:
  void executeEntryAction();
  Transition * transitions;
  void (* entryAction) ();
};



class Transition {
public:
  Transition(uint8_t event, uint8_t to);
  uint8_t event;
  uint8_t to;
};

class StateMachine {
public:
  StateMachine(State * states);
  void trigger(uint8_t event);
  void update();
  uint8_t getState();
  void start(uint8_t startState);
private:
  State * states;
  bool started;
  State * state;
  uint8_t queue[20]; // TODO replace full fifo library
  void transitionTo(uint8_t to);
};

#endif

