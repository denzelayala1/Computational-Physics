#ifndef Mage_h
#define Mage_h


 /*      /\  /\                       */
 /*     /  \/  \                      */
 /*    /        \   __ _   __ _  ___  */
 /*   /  /\  /\  \ / _` | / _` |/ _ \ */
 /*  /  /  \/  \  \ (_| || (_| |  __/ */
 /* /__/        \__\__,_| \__, |\___| */
 /*                        __/ |      */
 /*                       |___/       */

class Mage : public Entity{
 public :
   Mage( std::string name="", int attackPower=0 ) :
    Entity( "Mage", name, attackPower, 0, 0, 100) {
    };
  
   // In an attack, we reduce the hit points
   virtual int attack( Entity * other=0 ) {
    
    //check mana
    if ( mana_ < 10 ) {
    std::cout << name() << " does not have enough mana." << std::endl;
    return 0;
    }
    
    //Makes modulo math easier
     int turn= getTurn() + 1;

    //rouge does extra damage
     if(turn % 4 == 0){
        
        if ( other != 0 ) {
          setTarget(other);
        }

        if ( getTarget() != 0 ) {

          if ( getTarget()->isDead() ) {
            std::cout << name_ << " : target " << getTarget()->name() << " is already dead." << std::endl;
            myAttacks_[turn_].push_back( 0 ); 
            return 0;
          }

         mana_ -= 10;

          int ap = attackPower_ + 14 ;
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

     mana_ -= 10;
     return defaultAttack(other);
   };
};

#endif
