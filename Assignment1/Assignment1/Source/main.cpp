#include <iostream>
using std::cout;
using std::endl;

#include "Dweller.h"
#include "Outfit.h"
#include "Weapon.h"
#include "Item.h"
#include "GameObject.h"
#include "Vec2D.h"

void testNames();
void shouldNotCompile();

int main()
{
    testNames();
    //shouldNotCompile();

    Dweller d("One", 1234567);
    Outfit o("Outfit", 10, 1234567);
	Weapon w("Weapon", 16, 15);
	cout << d.getName() << endl;
	cout << o.getName() << endl;
	cout << w.getName() << endl;
    cout << "Dweller special " << d.getSPECIAL() << endl;
    d.assignOutfit(&o);
	d.assignWeapon(&w);
	cout << "Item special = " << o.getSPECIAL() << endl;
    cout << "Toatl special = " << d.getSPECIAL() << endl;
	cout << "Current weapon dmg = " << d.getAttackDmg() << endl;
	cout << endl;

	d.receiveHealthDamage(13);
	cout << "After receiving 13 health dmg, health = "<< d.getCurrentHealth() << endl; 
	d.receiveRadDamage(12);
	cout << "After receiving 12 rad damage, rad = " << d.getCurrentRadDamage() << endl;
	cout << "Max health : 100 - rad damage = " << d.getCurrentHealth() << endl;
	d.addStimpak(5);
	d.useStimpak();
	cout << "After use 1 stimpak, health = " <<d.getCurrentHealth() << endl;
	d.addRadAway(2);
	d.useRadAway();
	cout << "After use 1 radaway, rad = " << d.getCurrentRadDamage() << endl;
	d.useStimpak();
	cout << "After use 1 stimpak, health = " << d.getCurrentHealth() << endl;
	d.useRadAway();
	d.useStimpak();
	cout << "After using 1 more radaway and stimpak, health = " << d.getCurrentHealth() << endl;
	cout << endl;
	cout << "Item initial durability = 10" << endl;
	cout << "Weapon initial durability = 16" << endl;
	d.receiveEquipmentDamage(9);
	cout << "Item durability left = " << o.getDurability() << endl;
	cout << "After getting 9 damage to item durability, special = " << d.getSPECIAL() << endl;
	d.receiveEquipmentDamage(23);
	cout << "Weapon durability left = " << w.getDurability() << endl;
	cout << "After weapon get (9/2 = 4 damage), and (23/2 = 11 damage), dura = 16 - 15, dmg = " << d.getAttackDmg() << endl;
	cout << "After item gets another 22 damage, special = " << d.getSPECIAL()<<endl;
	d.receiveEquipmentDamage(2);
	cout << "After weapon gets 1 more dura dmg, total damage received = (32/2 = 16), weapon 0 dura, dmg = " << d.getAttackDmg() << endl;
 
    return 0;
}