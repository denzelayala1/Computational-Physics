#ifndef Rogue_h
#define Rogue_h


 /*  _____                         */
 /* |  __ \                        */
 /* | |__) |___   __ _ _   _  ___  */
 /* |  _  // _ \ / _` | | | |/ _ \ */
 /* | | \ \ (_) | (_| | |_| |  __/ */
 /* |_|  \_\___/ \__, |\__,_|\___| */
 /*               __/ |            */
 /*              |___/             */

class Rogue : public Entity{
 public :
   Rogue( std::string name="", int attackPower=0 ) :
    Entity( "Rogue", name, attackPower, 0, 0) {
    };
  
   // In an attack, we reduce the hit points
   virtual int attack( Entity * other=0 ) {
    
    
    //Makes modulo math easier
     int turn= getTurn() + 1;

    //rouge does extra damage
     if(turn % 3 == 0){
        
        if ( other != 0 ) {
          setTarget(other);
        }

        if ( getTarget() != 0 ) {
          if ( getTarget()->isDead() ) {
            std::cout << name_ << " : target " << getTarget()->name() << " is already dead." << std::endl;
            myAttacks_[turn_].push_back( 0 ); 
            return 0;
          }

          int ap = attackPower_ + 20 ;
          auto attacked = getTarget()->reduceHitPoints( ap );
          std::cout << name() << " attacked " << getTarget()->name() << " with attack power " << ap << " for damage " << attacked << std::endl;
          if ( myAttacks_.find(turn_) == myAttacks_.end() )
            myAttacks_[turn_] = action_vector(); 
          myAttacks_[turn_].push_back( attacked );
          return attacked;
        } 
        
        else {
          std::cout << name_ << " does not have a target to attack." << std::endl;
          myAttacks_[turn_].push_back( 0 ); 
          return 0;
        }

     }

     
     return defaultAttack(other);
   };
};

#endif
