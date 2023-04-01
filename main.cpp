#include <iostream>
#include <string>

using namespace std;

string Types[8] = {"Physical", "Fire", "Ice", "Force", "Electricity", "Light", "Dark", "Almighty"};
string Stats[7] = {"HP", "MP", "Strength", "Dexterity", "Vitality", "Agility", "Luck"};

class Skill{
    string name;
    int type, base_damage, MP_cost;
    float hit_rate, critical_rate;

public:

    // constructor
    Skill(string _name = "", const int _type = 0, const int _base_damage = 0, const int _MP_cost = 0, const float _hit_rate = 1, const float _critical_rate = 0.01): name(_name), type(_type), base_damage(_base_damage), MP_cost(_MP_cost), hit_rate(_hit_rate), critical_rate(_critical_rate){}

    //constructor de copiere
    Skill(const Skill & other): name(other.name), type(other.type), base_damage(other.base_damage), MP_cost(other.MP_cost), hit_rate(other.hit_rate), critical_rate(other.critical_rate){}

    //destructor
    ~Skill(){}

    //citire si afisare
    friend istream& operator>>(istream& in, Skill& s)
    {
        in >> s.name >> s.type >> s.base_damage >> s.MP_cost >> s.hit_rate >> s.critical_rate;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Skill& s)
    {
        return out << s.name << '\n' << "Deals " << s.base_damage << ' ' << Types[s.type] << ". Costs " << s.MP_cost << " MP. Has a hit rate of " << s.hit_rate << "and critical rate of " << s.critical_rate;
    }

    //operator de copiere
    Skill& operator=(const Skill& other)
    {
        name = other.name;
        type = other.type;
        base_damage = other.base_damage;
        MP_cost = other.MP_cost;
        hit_rate = other.hit_rate;
        critical_rate = other.critical_rate;
    }

    //gets
    int get_type(){return type;}
    int get_damage(){return base_damage;}
    int get_MP_cost(){return MP_cost;}
    float get_hit_rate(){return hit_rate;}
    float get_critical_rate(){return critical_rate;}

    //sets
    void set_name(string x){name=x;}
    void set_type(int x){type=x;}
    void set_damage(int x){base_damage=x;}
    void set_MP_cost(int x){MP_cost=x;}
    void set_hit_rate(float x){hit_rate=x;}
    void set_critical_rate(float x){critical_rate=x;}
};

class Accessory{
    string name;
    int type_buff;
    float buff_percentage;

public:
    //constructor
    Accessory(const string _name = "Basic Ring", const int _type_buff = 0, const int _buff_percentage = 0): name(_name), type_buff(_type_buff), buff_percentage(_buff_percentage){}
    //citire si afisare
    friend istream& operator>>(istream& in, Accessory& a)
    {
        return in >> a.name >> a.type_buff >> a.buff_percentage;
    }

    friend ostream& operator<<(ostream& out, const Accessory& a)
    {
        return out << a.name << '\n' << Types[a.type_buff] << " buffed by " << a.buff_percentage << '%';
    }

    //gets
    int get_type(){return type_buff;}
    float get_buff(){return buff_percentage;}

    //sets
    void set_name(string x){name=x;}
    void set_type(int x){type_buff=x;}
    void set_buff(float x){buff_percentage=x;}
};

class Armour{
    string name;
    int bonus_HP, bonus_MP, bonus_strength, bonus_dexterity, bonus_vitality, bonus_agility, bonus_luck;
public:
    //constructor
    Armour(const string _name = "Basic Armour", const int _bonus_HP = 0, const int _bonus_MP = 0, const int _bonus_strength = 0, const int _bonus_dexterity = 0, const int _bonus_vitality = 0, const int _bonus_agility = 0, const int _bonus_luck = 0): name(_name), bonus_HP(_bonus_HP), bonus_MP(_bonus_MP), bonus_strength(_bonus_strength), bonus_dexterity(_bonus_dexterity), bonus_vitality(_bonus_vitality), bonus_agility(_bonus_agility), bonus_luck(_bonus_luck) {}
    //citire si afisare
    friend istream& operator>>(istream& in, Armour& a)
    {
        return in >> a.name >> a.bonus_HP >> a.bonus_MP >> a.bonus_strength >> a.bonus_dexterity >> a.bonus_vitality >> a.bonus_agility >> a.bonus_luck;
    }

    friend ostream& operator<<(ostream& out, const Armour& ar)
    {
        out << ar.name;
        if(ar.bonus_HP)
           out << '\n' << "Bonus HP: " << ar.bonus_HP;
        if(ar.bonus_MP)
            out << '\n' << "Bonus MP: " << ar.bonus_MP;
        if(ar.bonus_strength)
            out << '\n' << "Bonus Strength: " << ar.bonus_strength;
        if(ar.bonus_dexterity)
            out << '\n' << "Bonus : " << ar.bonus_dexterity;
        if(ar.bonus_vitality)
            out << '\n' << "Bonus Vitality: " << ar.bonus_vitality;
        if(ar.bonus_agility)
            out << '\n' << "Bonus Agility: " << ar.bonus_agility;
        if(ar.bonus_luck)
            out << '\n' << "Bonus Luck: " << ar.bonus_luck;
        return out;
    }

    //gets
    int get_bHP(){return bonus_HP;}
    int get_bMP(){return bonus_MP;}
    int get_bstr(){return bonus_strength;}
    int get_bdex(){return bonus_dexterity;}
    int get_bvit(){return bonus_vitality;}
    int get_bagi(){return bonus_agility;}
    int get_blck(){return bonus_luck;}

    //sets
    void set_name(string x){name=x;}
    void get_bHP(int x){bonus_HP=x;}
    void get_bMP(int x){bonus_MP=x;}
    void get_bstr(int x){bonus_strength=x;}
    void get_bdex(int x){bonus_dexterity=x;}
    void get_bvit(int x){bonus_vitality=x;}
    void get_bagi(int x){bonus_agility=x;}
    void get_blck(int x){bonus_luck=x;}
};

class Consumable{
    string name;
    int HP_heal, MP_heal;
public:
    //constructor
    Consumable(const string _name = "Food", const int _HP_heal = 0, const int _MP_heal = 0): name(_name), HP_heal(_HP_heal), MP_heal(_MP_heal) {}
    //citire si afisare
    friend istream& operator>>(istream& in, Consumable& c)
    {
        return in >> c.name >> c.HP_heal >> c.MP_heal;
    }
    friend ostream& operator<<(ostream& out, const Consumable& c)
    {
        out << c.name << "\n Heals ";
        if(c.MP_heal == 0)
            out << c.HP_heal << " HP";
        else if (c.HP_heal == 0)
            out << c.MP_heal << " MP";
        else
            out << c.HP_heal << " HP and " << c.MP_heal << " MP";
        return out;
    }

    //gets
    int get_HP_heal(){return HP_heal;}
    int get_MP_heal(){return MP_heal;}

    //sets
    void set_name(string x){name=x;}
    void set_HP_heal(int x){HP_heal=x;}
    void set_MP_heal(int x){MP_heal=x;}
};

class Entity{
    string name;
    int nr_skills;
    Skill skill_list[8];
    int level, HP, MP, macca, strength, dexterity, vitality, agility, luck;
    int current_HP, current_MP;
    int weakness_chart[8];
    Accessory accessory;
    Armour armour;
    int nr_items;
    Consumable inventory[20];
public:
    //constructor
    Entity(const string _name = "Demon", const int _level = 1, const int _HP = 100, const int _MP = 30, const int _macca = 0, const int _strength = 3, const int _dexterity = 3, const int _vitality = 3, const int _agility = 3, const int _luck = 3): name(_name), level(_level), HP(_HP), MP(_MP), macca(_macca), strength(_strength), dexterity(_dexterity), vitality(_vitality), agility(_agility), luck(_luck)
    {
        current_HP = HP;
        current_MP = MP;
        nr_skills = 0;
        nr_items = 0;
        for(int i = 0; i <= 7; i++)
            weakness_chart[i] = 0;
    }
    //citire si afisare
    friend istream& operator>>(istream& in, Entity& e)
    {
        return in >> e.name >> e.level >> e.HP >> e.MP >> e.strength >> e.dexterity >> e.vitality >> e.agility >> e.luck;
    }

    friend ostream& operator<<(ostream& out, const Entity& e)
    {
        out << e.name << '\n' << "Level " << e.level << '\n';
        out << "HP: " << e.current_HP << '/' << e.HP << " MP: "<< e.current_MP << '/' << e.MP << '\n';
        out << "Strength: " << e.strength << " Dexterity: " << e.dexterity << " Vitality: " << e.vitality << " Agility: "<< e.agility << " Luck: " << e.luck << '\n';
        out << "Number of skills: " << e.nr_skills << '\n';
        for(int i = 0; i < e.nr_skills; i++)
            out << e.skill_list[i] << '\n';
        for(int i = 0; i < 8; i++)
        {
            switch (e.weakness_chart[i]) {
                case -1: out << "Weak to "; break;
                case 0: out << "Normal damage from "; break;
                case 1: out << "Resistant to "; break;
                case 2: out << "No damage from "; break;
                case 3: out << "Reflects "; break;
                case 4: out << "Absorbs "; break;
            }
            out << Types[i] << '\n';
        }
        out << "Armour: " << e.armour << '\n';
        out << "Accessory: " << e.accessory << '\n';
        out << "Number of items in inventory: " << e.nr_items << '\n';
        for(int i = 0; i < e.nr_items; i++)
            out << e.inventory[i] << '\n';
        return out;
    }

    //use skill
    /*void UseSkill(Skill s, Entity& enemy)
    {
        int attack = 0;
        if(s.type == 0)
            attack = strength;
        else
            attack = dexterity;
        int damage_dealt = s.base_damage * ((float)(attack) / (float)(enemy.vitality));
    }*/
};

int main() {
    Entity pixie("Pixie", 3, 50, 34, 4, 7, 3, 6, 4);
    cout << pixie;
    return 0;
}
