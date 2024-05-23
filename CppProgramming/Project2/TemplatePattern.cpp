#include <iostream>

class character {
protected:
	int hp;
	int location[2];
public:
	character() :hp{ 0 }, location{ 0,0 } {};
	void set_location(int x, int y) {
		location[0] = x;
		location[1] = y;
	}
};

class player {
protected:
	int hp;
public:
	player() :hp{ 0 } {};
};


class monster {
public:
	virtual void find_route(player& target_player) =0;
	virtual bool attack_target(player* target_player) = 0;
	virtual void check_target(player& target_player) = 0;
	virtual void attack_special(player& target_player) = 0;
	void set_location(int x, int y) 
	{
		monster_body.set_location(x, y);
	};
	virtual ~monster() = default;

protected:
	character* target_playerpower;
private:
	character monster_body;
};

class monster_a : public monster
{
public:
	virtual void find_route(player& target_player) override;
	virtual bool attack_target(player* target_player) override;
	virtual void check_target(player& target_player) override;
	virtual void attack_special(player& target_player) override;
};

void monster_a::find_route(player& target_player)
{
	std::cout << "타깃 찾아가기" << std::endl;
}

bool monster_a::attack_target(player* target_player)
{
	return false;
}

void monster_a::check_target(player& target_player)
{
	std::cout << "타깃이 있는지 체크" << std::endl;
}

void monster_a::attack_special(player& target_player)
{
	std::cout << "특별 공격 실행" << std::endl;
}
