#include "StateMachine.h"
#include <stdlib.h>
#define len(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

State::State(uint8_t id, void (* entryAction) (), Transition * transitions){
  this->id = id;
  this->entryAction = entryAction;
  this->transitions = transitions;
};


void State::executeEntryAction(){
  // Execute action
  if(this->entryAction != NULL)
    this->entryAction();
}


Transition::Transition(uint8_t event, uint8_t to){
  this->event = event;
  this->to = to;
};


StateMachine::StateMachine(State * states){
  this->states = states;
};

void StateMachine::trigger(uint8_t event){
  // Print trigger
  // TODO add trigger
  
};
void StateMachine::update(){
  
  // TODO while more events
  uint8_t ev; 
  while(ev){
    
   // Does the current state have a trigger for this state?
   Transition * t = state->findTransition(ev);
   
   // nope
   if(t == NULL)
     continue;
    
    transitionTo(t->to);
  }
  
  // Does the current state have an any-state?
   Transition * t = state->findTransition(E_ANY);
   
   // yes
   if(t != NULL){
     transitionTo(t->to);
   }
  
};

Transition * State::findTransition(uint8_t ev){
   for(uint8_t i = 0; i <  len(transitions); i++){
     if(transitions[i].event == ev){
       return &transitions[i];
     }
   }
   return NULL;
}

void StateMachine::transitionTo(uint8_t to){
     // reset sleep mode
     // reset rtc alarmss
     // reset watchdog
     // Print state change
     
     
   for(uint8_t i = 0; i <  len(states); i++){
     if(states[i].id == to){
       state = &states[i];
       break;
     }
   }
     
}; 


