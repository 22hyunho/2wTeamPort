#include "stdafx.h"
#include "Player.h"
#include "Pattern.h"

HRESULT Player::init(int pokemonNum, int level)
{
	//포켓몬
	_pokemon = POKEDEX->makePokemon(pokemonNum);
	_pokemon->init();

	_level = level;
	_EXP = (_level - 1) * (_level - 1) * 100;

	_realStat = BATTLEMANAGER->statCalculation(this);
	_currentHP = _realStat.hp;

	return S_OK;
}

HRESULT Player::initXY(float x, float y)
{
	//허기
	_starve = 100;

	//좌표
	_initX = _destX = _x = x;
	_initY = _destY = _y = y;
	_body = RectMakeCenter(_x * TILEWIDTH + TILEWIDTH / 2, _y * TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH, TILEHEIGHT);

	_changeState = false;
	_turnCount = 0;

	return S_OK;
}

void Player::release()
{
	SOUNDMANAGER->stop("LevelUp");
	SOUNDMANAGER->stop("Option");
}

void Player::update()
{
	//방향 설정하고 포켓몬 상태 업데이트
	setDirect();

	//상태에 따라 함수 호출
	switch (_playerState) {
	case POKEMON_STATE_MOVE:
		if (!_changeState) {
			_pokemon->changeState(_playerState);
			_changeState = true;
			_turnCount++;
		}
		move();
		break;
	case POKEMON_STATE_ATTACK:
		attack();
		if (!_changeState) {
			_pokemon->changeState(_playerState);
			_changeState = true;
			_turnCount++;
		}
		break;
	case POKEMON_STATE_SATTACK:
		sattack();
		if (!_changeState) {
			_pokemon->changeState(_playerState);
			_changeState = true;
			_turnCount++;
		}
		break;
	default:
		_playerState = END_POKEMON_STATE;
		break;
	}

	_body = RectMakeCenter(_x * TILEWIDTH + TILEWIDTH / 2, _y * TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH, TILEHEIGHT);

	//_pokemon->update();
}

void Player::render()
{
	if (PRINTMANAGER->isDebug()) {
		WCHAR str[128];
		swprintf_s(str, L"x : %f", _x);
		DTDMANAGER->printText(str, dRectMake(_body.left, _body.top - 60, 100, 20));
		swprintf_s(str, L"y : %f", _y);
		DTDMANAGER->printText(str, dRectMake(_body.left, _body.top - 40, 100, 20));
		swprintf_s(str, L"name : %s", _pokemon->getName().c_str());
		DTDMANAGER->printText(str, dRectMake(_body.left, _body.top - 20, 100, 20));

		DTDMANAGER->Rectangle(_body);
	}

	_pokemon->render(_x, _y);
}

void Player::changePattern(PLAYER_PATTERN pattern)
{
	if (_currentPattern == pattern) return;


	//패턴 갱신
	_currentPattern = pattern;
	_pattern[_currentPattern]->init(this);
}

void Player::setDirect()
{
	_direct = 0;

	if (_x != _destX) {
		if (_x < _destX)
			_direct |= RIGHT;
		else
			_direct |= LEFT;
	}

	if (_y != _destY) {
		if (_y > _destY)
			_direct |= UP;
		else
			_direct |= DOWN;
	}

	if (_direct)
		_pokemon->changeDirect(_direct);
}

void Player::resetXY()
{
	_initX = _destX = _x;
	_initY = _destY = _y;
	_changeState = false;
}

void Player::move()
{
	if (_x != _destX)	_x += cosf(_pokemon->getAngle()) / 16;
	if (_y != _destY)	_y += -sinf(_pokemon->getAngle()) / 16;

	float limit = 1.4142;
	if (_direct == RIGHT || _direct == LEFT || _direct == UP || _direct == DOWN) limit = 1.0;

	//이동 시작지점과 현재 위치 거리가 타일 1칸이상이 되면 (== 이동거리가 타일 1칸이상되면) 이동 끝
	//이전에는 이동 목적지와 현재 위치 거리가 일정 거리만큼 가까워지면 이동 끝
	if (getDistance(_initX, _initY, _x, _y) >= limit ||
		getDistance(_destX, _destY, _x, _y) <= limit / 16) {
		_x = _destX;
		_y = _destY;

		//_pokemon->changeState(POKEMON_STATE_DEFAULT);
		_playerState = END_POKEMON_STATE;
	}
}

void Player::attack()
{
	if (!_pokemon->getAttack()) {
		_playerState = END_POKEMON_STATE;
		return;
	}
	
	if (_selectedSkill) {
		_selectedSkill->useSkill();
		//DIALOGMANAGER->useSkillLog(this, _selectedSkill);
		_selectedSkill = nullptr;
	}
}

void Player::sattack()
{
	if (!_pokemon->getSattack()) {
		_playerState = END_POKEMON_STATE;
		return;
	}

	if (_selectedSkill) {
		_selectedSkill->useSkill();
		DIALOGMANAGER->useSkillLog(this, _selectedSkill);
		_selectedSkill = nullptr;
	}
}

void Player::resetHP()
{
	_currentHP = _realStat.hp;
}

void Player::resetPP()
{
	for (int i = 0; i < 4; i++) {
		if (_skill[i])
			_skill[i]->init(this);
	}
}

void Player::loadSkill(int num)
{
	for (int i = 0; i < 4; i++) {
		if (!_skill[i]) {
			_skill[i] = SKILLDEX->makeSkill(num);
			_skill[i]->init(this);
			break;
		}
	}
}

void Player::setSkill(int num)
{
	_skill[0] = nullptr;
	_skill[1] = nullptr;
	_skill[2] = nullptr;
	_skill[3] = nullptr;

	vector<int> skillList = _pokemon->getSkill();
	vector<int> skills;
	bool same;
	int numbers = num;

	if (skillList.size() < num)
		numbers = skillList.size();

	for (int i = 0; i < numbers; i++) {

		int skillNum = skillList[RND->getInt(skillList.size())];
		same = true;

		while (same && skills.size()) {
			skillNum = skillList[RND->getInt(skillList.size())];
			for (int i = 0; i < skills.size(); i++) {
				if (skillNum == skills[i]) {
					same = true;
					break;
				}
				else
					same = false;
			}
		}
		skills.push_back(skillNum);

		_skill[i] = SKILLDEX->makeSkill(skillNum);
		_skill[i]->init(this);
	}
}

void Player::useSkill(int num)
{
	if (num == -1) {
		_selectedSkill = _default;
		_playerState = POKEMON_STATE_ATTACK;
		_pokemon->setAttack(true);
	}
	else {
		_selectedSkill = _skill[num];
		_playerState = POKEMON_STATE_SATTACK;
		_pokemon->setSattack(true);
	}
}

void Player::hitDamage(int num)
{
	_currentHP -= abs(num);
	if (_currentHP < 0)
		_currentHP = 0;
}

void Player::addEXP(int num)
{
	_EXP += num;

	if (_EXP >= (_level) * (_level) * 100)
		levelUP();
}

void Player::levelUP()
{
	_level++;
	_realStat = BATTLEMANAGER->statCalculation(this);

	//레벨업하면 잠시 메뉴를 띄워야함
	//레벨업 로그
	SOUNDMANAGER->play("LevelUp");
	DIALOGMANAGER->levelUPLog(this, _level);
	UIMANAGER->getCurrentDownMenu()->setHidden(true);
	DIALOGMANAGER->loadMetaData(L"data/levelUP");
}
