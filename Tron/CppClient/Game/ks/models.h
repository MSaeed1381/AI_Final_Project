#ifndef _KS_MODELS_H_
#define _KS_MODELS_H_

#include <string>
#include <vector>
#include <map>
#include <array>


namespace ks
{

#ifndef _KS_OBJECT_
#define _KS_OBJECT_

class KSObject
{
public:
	static inline const std::string nameStatic() { return ""; }
	virtual inline const std::string name() const = 0;
	virtual std::string serialize() const = 0;
	virtual unsigned int deserialize(const std::string &, unsigned int = 0) = 0;
};

#endif // _KS_OBJECT_


namespace models
{

enum class ECell
{
	Empty = 0,
	AreaWall = 1,
	BlueWall = 2,
	YellowWall = 3,
};


enum class EDirection
{
	Up = 0,
	Right = 1,
	Down = 2,
	Left = 3,
};


class Constants : public KSObject
{

protected:

	int __maxCycles;
	int __initHealth;
	int __wallBreakerCooldown;
	int __wallBreakerDuration;
	int __wallScoreCoefficient;
	int __areaWallCrashScore;
	int __myWallCrashScore;
	int __enemyWallCrashScore;

	bool __has_maxCycles;
	bool __has_initHealth;
	bool __has_wallBreakerCooldown;
	bool __has_wallBreakerDuration;
	bool __has_wallScoreCoefficient;
	bool __has_areaWallCrashScore;
	bool __has_myWallCrashScore;
	bool __has_enemyWallCrashScore;


public: // getters

	inline int maxCycles() const
	{
		return __maxCycles;
	}
	
	inline int initHealth() const
	{
		return __initHealth;
	}
	
	inline int wallBreakerCooldown() const
	{
		return __wallBreakerCooldown;
	}
	
	inline int wallBreakerDuration() const
	{
		return __wallBreakerDuration;
	}
	
	inline int wallScoreCoefficient() const
	{
		return __wallScoreCoefficient;
	}
	
	inline int areaWallCrashScore() const
	{
		return __areaWallCrashScore;
	}
	
	inline int myWallCrashScore() const
	{
		return __myWallCrashScore;
	}
	
	inline int enemyWallCrashScore() const
	{
		return __enemyWallCrashScore;
	}
	

public: // reference getters

	inline int &ref_maxCycles() const
	{
		return (int&) __maxCycles;
	}
	
	inline int &ref_initHealth() const
	{
		return (int&) __initHealth;
	}
	
	inline int &ref_wallBreakerCooldown() const
	{
		return (int&) __wallBreakerCooldown;
	}
	
	inline int &ref_wallBreakerDuration() const
	{
		return (int&) __wallBreakerDuration;
	}
	
	inline int &ref_wallScoreCoefficient() const
	{
		return (int&) __wallScoreCoefficient;
	}
	
	inline int &ref_areaWallCrashScore() const
	{
		return (int&) __areaWallCrashScore;
	}
	
	inline int &ref_myWallCrashScore() const
	{
		return (int&) __myWallCrashScore;
	}
	
	inline int &ref_enemyWallCrashScore() const
	{
		return (int&) __enemyWallCrashScore;
	}
	

public: // setters

	inline void maxCycles(const int &maxCycles)
	{
		__maxCycles = maxCycles;
		has_maxCycles(true);
	}
	
	inline void initHealth(const int &initHealth)
	{
		__initHealth = initHealth;
		has_initHealth(true);
	}
	
	inline void wallBreakerCooldown(const int &wallBreakerCooldown)
	{
		__wallBreakerCooldown = wallBreakerCooldown;
		has_wallBreakerCooldown(true);
	}
	
	inline void wallBreakerDuration(const int &wallBreakerDuration)
	{
		__wallBreakerDuration = wallBreakerDuration;
		has_wallBreakerDuration(true);
	}
	
	inline void wallScoreCoefficient(const int &wallScoreCoefficient)
	{
		__wallScoreCoefficient = wallScoreCoefficient;
		has_wallScoreCoefficient(true);
	}
	
	inline void areaWallCrashScore(const int &areaWallCrashScore)
	{
		__areaWallCrashScore = areaWallCrashScore;
		has_areaWallCrashScore(true);
	}
	
	inline void myWallCrashScore(const int &myWallCrashScore)
	{
		__myWallCrashScore = myWallCrashScore;
		has_myWallCrashScore(true);
	}
	
	inline void enemyWallCrashScore(const int &enemyWallCrashScore)
	{
		__enemyWallCrashScore = enemyWallCrashScore;
		has_enemyWallCrashScore(true);
	}
	

public: // has_attribute getters

	inline bool has_maxCycles() const
	{
		return __has_maxCycles;
	}
	
	inline bool has_initHealth() const
	{
		return __has_initHealth;
	}
	
	inline bool has_wallBreakerCooldown() const
	{
		return __has_wallBreakerCooldown;
	}
	
	inline bool has_wallBreakerDuration() const
	{
		return __has_wallBreakerDuration;
	}
	
	inline bool has_wallScoreCoefficient() const
	{
		return __has_wallScoreCoefficient;
	}
	
	inline bool has_areaWallCrashScore() const
	{
		return __has_areaWallCrashScore;
	}
	
	inline bool has_myWallCrashScore() const
	{
		return __has_myWallCrashScore;
	}
	
	inline bool has_enemyWallCrashScore() const
	{
		return __has_enemyWallCrashScore;
	}
	

public: // has_attribute setters

	inline void has_maxCycles(const bool &has_maxCycles)
	{
		__has_maxCycles = has_maxCycles;
	}
	
	inline void has_initHealth(const bool &has_initHealth)
	{
		__has_initHealth = has_initHealth;
	}
	
	inline void has_wallBreakerCooldown(const bool &has_wallBreakerCooldown)
	{
		__has_wallBreakerCooldown = has_wallBreakerCooldown;
	}
	
	inline void has_wallBreakerDuration(const bool &has_wallBreakerDuration)
	{
		__has_wallBreakerDuration = has_wallBreakerDuration;
	}
	
	inline void has_wallScoreCoefficient(const bool &has_wallScoreCoefficient)
	{
		__has_wallScoreCoefficient = has_wallScoreCoefficient;
	}
	
	inline void has_areaWallCrashScore(const bool &has_areaWallCrashScore)
	{
		__has_areaWallCrashScore = has_areaWallCrashScore;
	}
	
	inline void has_myWallCrashScore(const bool &has_myWallCrashScore)
	{
		__has_myWallCrashScore = has_myWallCrashScore;
	}
	
	inline void has_enemyWallCrashScore(const bool &has_enemyWallCrashScore)
	{
		__has_enemyWallCrashScore = has_enemyWallCrashScore;
	}
	

public:

	Constants()
	{
		has_maxCycles(false);
		has_initHealth(false);
		has_wallBreakerCooldown(false);
		has_wallBreakerDuration(false);
		has_wallScoreCoefficient(false);
		has_areaWallCrashScore(false);
		has_myWallCrashScore(false);
		has_enemyWallCrashScore(false);
	}
	
	static inline const std::string nameStatic()
	{
		return "Constants";
	}
	
	virtual inline const std::string name() const
	{
		return "Constants";
	}
	
	std::string serialize() const
	{
		std::string s = "";
		
		// serialize maxCycles
		s += __has_maxCycles;
		if (__has_maxCycles)
		{
			int tmp1 = __maxCycles;
			auto tmp2 = reinterpret_cast<char*>(&tmp1);
			s += std::string(tmp2, sizeof(int));
		}
		
		// serialize initHealth
		s += __has_initHealth;
		if (__has_initHealth)
		{
			int tmp4 = __initHealth;
			auto tmp5 = reinterpret_cast<char*>(&tmp4);
			s += std::string(tmp5, sizeof(int));
		}
		
		// serialize wallBreakerCooldown
		s += __has_wallBreakerCooldown;
		if (__has_wallBreakerCooldown)
		{
			int tmp7 = __wallBreakerCooldown;
			auto tmp8 = reinterpret_cast<char*>(&tmp7);
			s += std::string(tmp8, sizeof(int));
		}
		
		// serialize wallBreakerDuration
		s += __has_wallBreakerDuration;
		if (__has_wallBreakerDuration)
		{
			int tmp10 = __wallBreakerDuration;
			auto tmp11 = reinterpret_cast<char*>(&tmp10);
			s += std::string(tmp11, sizeof(int));
		}
		
		// serialize wallScoreCoefficient
		s += __has_wallScoreCoefficient;
		if (__has_wallScoreCoefficient)
		{
			int tmp13 = __wallScoreCoefficient;
			auto tmp14 = reinterpret_cast<char*>(&tmp13);
			s += std::string(tmp14, sizeof(int));
		}
		
		// serialize areaWallCrashScore
		s += __has_areaWallCrashScore;
		if (__has_areaWallCrashScore)
		{
			int tmp16 = __areaWallCrashScore;
			auto tmp17 = reinterpret_cast<char*>(&tmp16);
			s += std::string(tmp17, sizeof(int));
		}
		
		// serialize myWallCrashScore
		s += __has_myWallCrashScore;
		if (__has_myWallCrashScore)
		{
			int tmp19 = __myWallCrashScore;
			auto tmp20 = reinterpret_cast<char*>(&tmp19);
			s += std::string(tmp20, sizeof(int));
		}
		
		// serialize enemyWallCrashScore
		s += __has_enemyWallCrashScore;
		if (__has_enemyWallCrashScore)
		{
			int tmp22 = __enemyWallCrashScore;
			auto tmp23 = reinterpret_cast<char*>(&tmp22);
			s += std::string(tmp23, sizeof(int));
		}
		
		return s;
	}
	
	unsigned int deserialize(const std::string &s, unsigned int offset=0)
	{
		// deserialize maxCycles
		__has_maxCycles = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_maxCycles)
		{
			__maxCycles = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		// deserialize initHealth
		__has_initHealth = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_initHealth)
		{
			__initHealth = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		// deserialize wallBreakerCooldown
		__has_wallBreakerCooldown = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_wallBreakerCooldown)
		{
			__wallBreakerCooldown = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		// deserialize wallBreakerDuration
		__has_wallBreakerDuration = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_wallBreakerDuration)
		{
			__wallBreakerDuration = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		// deserialize wallScoreCoefficient
		__has_wallScoreCoefficient = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_wallScoreCoefficient)
		{
			__wallScoreCoefficient = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		// deserialize areaWallCrashScore
		__has_areaWallCrashScore = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_areaWallCrashScore)
		{
			__areaWallCrashScore = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		// deserialize myWallCrashScore
		__has_myWallCrashScore = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_myWallCrashScore)
		{
			__myWallCrashScore = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		// deserialize enemyWallCrashScore
		__has_enemyWallCrashScore = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_enemyWallCrashScore)
		{
			__enemyWallCrashScore = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		return offset;
	}
};


class Position : public KSObject
{

protected:

	int __x;
	int __y;

	bool __has_x;
	bool __has_y;


public: // getters

	inline int x() const
	{
		return __x;
	}
	
	inline int y() const
	{
		return __y;
	}
	

public: // reference getters

	inline int &ref_x() const
	{
		return (int&) __x;
	}
	
	inline int &ref_y() const
	{
		return (int&) __y;
	}
	

public: // setters

	inline void x(const int &x)
	{
		__x = x;
		has_x(true);
	}
	
	inline void y(const int &y)
	{
		__y = y;
		has_y(true);
	}
	

public: // has_attribute getters

	inline bool has_x() const
	{
		return __has_x;
	}
	
	inline bool has_y() const
	{
		return __has_y;
	}
	

public: // has_attribute setters

	inline void has_x(const bool &has_x)
	{
		__has_x = has_x;
	}
	
	inline void has_y(const bool &has_y)
	{
		__has_y = has_y;
	}
	

public:

	Position()
	{
		has_x(false);
		has_y(false);
	}
	
	static inline const std::string nameStatic()
	{
		return "Position";
	}
	
	virtual inline const std::string name() const
	{
		return "Position";
	}
	
	std::string serialize() const
	{
		std::string s = "";
		
		// serialize x
		s += __has_x;
		if (__has_x)
		{
			int tmp25 = __x;
			auto tmp26 = reinterpret_cast<char*>(&tmp25);
			s += std::string(tmp26, sizeof(int));
		}
		
		// serialize y
		s += __has_y;
		if (__has_y)
		{
			int tmp28 = __y;
			auto tmp29 = reinterpret_cast<char*>(&tmp28);
			s += std::string(tmp29, sizeof(int));
		}
		
		return s;
	}
	
	unsigned int deserialize(const std::string &s, unsigned int offset=0)
	{
		// deserialize x
		__has_x = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_x)
		{
			__x = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		// deserialize y
		__has_y = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_y)
		{
			__y = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		return offset;
	}
};


class Agent : public KSObject
{

protected:

	int __health;
	Position __position;
	EDirection __direction;
	int __wallBreakerCooldown;
	int __wallBreakerRemTime;

	bool __has_health;
	bool __has_position;
	bool __has_direction;
	bool __has_wallBreakerCooldown;
	bool __has_wallBreakerRemTime;


public: // getters

	inline int health() const
	{
		return __health;
	}
	
	inline Position position() const
	{
		return __position;
	}
	
	inline EDirection direction() const
	{
		return __direction;
	}
	
	inline int wallBreakerCooldown() const
	{
		return __wallBreakerCooldown;
	}
	
	inline int wallBreakerRemTime() const
	{
		return __wallBreakerRemTime;
	}
	

public: // reference getters

	inline int &ref_health() const
	{
		return (int&) __health;
	}
	
	inline Position &ref_position() const
	{
		return (Position&) __position;
	}
	
	inline EDirection &ref_direction() const
	{
		return (EDirection&) __direction;
	}
	
	inline int &ref_wallBreakerCooldown() const
	{
		return (int&) __wallBreakerCooldown;
	}
	
	inline int &ref_wallBreakerRemTime() const
	{
		return (int&) __wallBreakerRemTime;
	}
	

public: // setters

	inline void health(const int &health)
	{
		__health = health;
		has_health(true);
	}
	
	inline void position(const Position &position)
	{
		__position = position;
		has_position(true);
	}
	
	inline void direction(const EDirection &direction)
	{
		__direction = direction;
		has_direction(true);
	}
	
	inline void wallBreakerCooldown(const int &wallBreakerCooldown)
	{
		__wallBreakerCooldown = wallBreakerCooldown;
		has_wallBreakerCooldown(true);
	}
	
	inline void wallBreakerRemTime(const int &wallBreakerRemTime)
	{
		__wallBreakerRemTime = wallBreakerRemTime;
		has_wallBreakerRemTime(true);
	}
	

public: // has_attribute getters

	inline bool has_health() const
	{
		return __has_health;
	}
	
	inline bool has_position() const
	{
		return __has_position;
	}
	
	inline bool has_direction() const
	{
		return __has_direction;
	}
	
	inline bool has_wallBreakerCooldown() const
	{
		return __has_wallBreakerCooldown;
	}
	
	inline bool has_wallBreakerRemTime() const
	{
		return __has_wallBreakerRemTime;
	}
	

public: // has_attribute setters

	inline void has_health(const bool &has_health)
	{
		__has_health = has_health;
	}
	
	inline void has_position(const bool &has_position)
	{
		__has_position = has_position;
	}
	
	inline void has_direction(const bool &has_direction)
	{
		__has_direction = has_direction;
	}
	
	inline void has_wallBreakerCooldown(const bool &has_wallBreakerCooldown)
	{
		__has_wallBreakerCooldown = has_wallBreakerCooldown;
	}
	
	inline void has_wallBreakerRemTime(const bool &has_wallBreakerRemTime)
	{
		__has_wallBreakerRemTime = has_wallBreakerRemTime;
	}
	

public:

	Agent()
	{
		has_health(false);
		has_position(false);
		has_direction(false);
		has_wallBreakerCooldown(false);
		has_wallBreakerRemTime(false);
	}
	
	static inline const std::string nameStatic()
	{
		return "Agent";
	}
	
	virtual inline const std::string name() const
	{
		return "Agent";
	}
	
	std::string serialize() const
	{
		std::string s = "";
		
		// serialize health
		s += __has_health;
		if (__has_health)
		{
			int tmp31 = __health;
			auto tmp32 = reinterpret_cast<char*>(&tmp31);
			s += std::string(tmp32, sizeof(int));
		}
		
		// serialize position
		s += __has_position;
		if (__has_position)
		{
			s += __position.serialize();
		}
		
		// serialize direction
		s += __has_direction;
		if (__has_direction)
		{
			char tmp34 = (char) __direction;
			auto tmp35 = reinterpret_cast<char*>(&tmp34);
			s += std::string(tmp35, sizeof(char));
		}
		
		// serialize wallBreakerCooldown
		s += __has_wallBreakerCooldown;
		if (__has_wallBreakerCooldown)
		{
			int tmp37 = __wallBreakerCooldown;
			auto tmp38 = reinterpret_cast<char*>(&tmp37);
			s += std::string(tmp38, sizeof(int));
		}
		
		// serialize wallBreakerRemTime
		s += __has_wallBreakerRemTime;
		if (__has_wallBreakerRemTime)
		{
			int tmp40 = __wallBreakerRemTime;
			auto tmp41 = reinterpret_cast<char*>(&tmp40);
			s += std::string(tmp41, sizeof(int));
		}
		
		return s;
	}
	
	unsigned int deserialize(const std::string &s, unsigned int offset=0)
	{
		// deserialize health
		__has_health = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_health)
		{
			__health = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		// deserialize position
		__has_position = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_position)
		{
			offset = __position.deserialize(s, offset);
		}
		
		// deserialize direction
		__has_direction = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_direction)
		{
			char tmp42;
			tmp42 = *((char*) (&s[offset]));
			offset += sizeof(char);
			__direction = (EDirection) tmp42;
		}
		
		// deserialize wallBreakerCooldown
		__has_wallBreakerCooldown = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_wallBreakerCooldown)
		{
			__wallBreakerCooldown = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		// deserialize wallBreakerRemTime
		__has_wallBreakerRemTime = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_wallBreakerRemTime)
		{
			__wallBreakerRemTime = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		return offset;
	}
};


class World : public KSObject
{

protected:

	std::vector<std::vector<ECell>> __board;
	std::map<std::string, Agent> __agents;
	std::map<std::string, int> __scores;
	Constants __constants;

	bool __has_board;
	bool __has_agents;
	bool __has_scores;
	bool __has_constants;


public: // getters

	inline std::vector<std::vector<ECell>> board() const
	{
		return __board;
	}
	
	inline std::map<std::string, Agent> agents() const
	{
		return __agents;
	}
	
	inline std::map<std::string, int> scores() const
	{
		return __scores;
	}
	
	inline Constants constants() const
	{
		return __constants;
	}
	

public: // reference getters

	inline std::vector<std::vector<ECell>> &ref_board() const
	{
		return (std::vector<std::vector<ECell>>&) __board;
	}
	
	inline std::map<std::string, Agent> &ref_agents() const
	{
		return (std::map<std::string, Agent>&) __agents;
	}
	
	inline std::map<std::string, int> &ref_scores() const
	{
		return (std::map<std::string, int>&) __scores;
	}
	
	inline Constants &ref_constants() const
	{
		return (Constants&) __constants;
	}
	

public: // setters

	inline void board(const std::vector<std::vector<ECell>> &board)
	{
		__board = board;
		has_board(true);
	}
	
	inline void agents(const std::map<std::string, Agent> &agents)
	{
		__agents = agents;
		has_agents(true);
	}
	
	inline void scores(const std::map<std::string, int> &scores)
	{
		__scores = scores;
		has_scores(true);
	}
	
	inline void constants(const Constants &constants)
	{
		__constants = constants;
		has_constants(true);
	}
	

public: // has_attribute getters

	inline bool has_board() const
	{
		return __has_board;
	}
	
	inline bool has_agents() const
	{
		return __has_agents;
	}
	
	inline bool has_scores() const
	{
		return __has_scores;
	}
	
	inline bool has_constants() const
	{
		return __has_constants;
	}
	

public: // has_attribute setters

	inline void has_board(const bool &has_board)
	{
		__has_board = has_board;
	}
	
	inline void has_agents(const bool &has_agents)
	{
		__has_agents = has_agents;
	}
	
	inline void has_scores(const bool &has_scores)
	{
		__has_scores = has_scores;
	}
	
	inline void has_constants(const bool &has_constants)
	{
		__has_constants = has_constants;
	}
	

public:

	World()
	{
		has_board(false);
		has_agents(false);
		has_scores(false);
		has_constants(false);
	}
	
	static inline const std::string nameStatic()
	{
		return "World";
	}
	
	virtual inline const std::string name() const
	{
		return "World";
	}
	
	std::string serialize() const
	{
		std::string s = "";
		
		// serialize board
		s += __has_board;
		if (__has_board)
		{
			std::string tmp43 = "";
			unsigned int tmp45 = __board.size();
			auto tmp46 = reinterpret_cast<char*>(&tmp45);
			tmp43 += std::string(tmp46, sizeof(unsigned int));
			while (tmp43.size() && tmp43.back() == 0)
				tmp43.pop_back();
			unsigned char tmp48 = tmp43.size();
			auto tmp49 = reinterpret_cast<char*>(&tmp48);
			s += std::string(tmp49, sizeof(unsigned char));
			s += tmp43;
			
			for (auto &tmp50 : __board)
			{
				s += '\x01';
				std::string tmp51 = "";
				unsigned int tmp53 = tmp50.size();
				auto tmp54 = reinterpret_cast<char*>(&tmp53);
				tmp51 += std::string(tmp54, sizeof(unsigned int));
				while (tmp51.size() && tmp51.back() == 0)
					tmp51.pop_back();
				unsigned char tmp56 = tmp51.size();
				auto tmp57 = reinterpret_cast<char*>(&tmp56);
				s += std::string(tmp57, sizeof(unsigned char));
				s += tmp51;
				
				for (auto &tmp58 : tmp50)
				{
					s += '\x01';
					char tmp60 = (char) tmp58;
					auto tmp61 = reinterpret_cast<char*>(&tmp60);
					s += std::string(tmp61, sizeof(char));
				}
			}
		}
		
		// serialize agents
		s += __has_agents;
		if (__has_agents)
		{
			std::string tmp62 = "";
			unsigned int tmp64 = __agents.size();
			auto tmp65 = reinterpret_cast<char*>(&tmp64);
			tmp62 += std::string(tmp65, sizeof(unsigned int));
			while (tmp62.size() && tmp62.back() == 0)
				tmp62.pop_back();
			unsigned char tmp67 = tmp62.size();
			auto tmp68 = reinterpret_cast<char*>(&tmp67);
			s += std::string(tmp68, sizeof(unsigned char));
			s += tmp62;
			
			for (auto &tmp69 : __agents)
			{
				s += '\x01';
				std::string tmp70 = "";
				unsigned int tmp72 = tmp69.first.size();
				auto tmp73 = reinterpret_cast<char*>(&tmp72);
				tmp70 += std::string(tmp73, sizeof(unsigned int));
				while (tmp70.size() && tmp70.back() == 0)
					tmp70.pop_back();
				unsigned char tmp75 = tmp70.size();
				auto tmp76 = reinterpret_cast<char*>(&tmp75);
				s += std::string(tmp76, sizeof(unsigned char));
				s += tmp70;
				
				s += tmp69.first;
				
				s += '\x01';
				s += tmp69.second.serialize();
			}
		}
		
		// serialize scores
		s += __has_scores;
		if (__has_scores)
		{
			std::string tmp77 = "";
			unsigned int tmp79 = __scores.size();
			auto tmp80 = reinterpret_cast<char*>(&tmp79);
			tmp77 += std::string(tmp80, sizeof(unsigned int));
			while (tmp77.size() && tmp77.back() == 0)
				tmp77.pop_back();
			unsigned char tmp82 = tmp77.size();
			auto tmp83 = reinterpret_cast<char*>(&tmp82);
			s += std::string(tmp83, sizeof(unsigned char));
			s += tmp77;
			
			for (auto &tmp84 : __scores)
			{
				s += '\x01';
				std::string tmp85 = "";
				unsigned int tmp87 = tmp84.first.size();
				auto tmp88 = reinterpret_cast<char*>(&tmp87);
				tmp85 += std::string(tmp88, sizeof(unsigned int));
				while (tmp85.size() && tmp85.back() == 0)
					tmp85.pop_back();
				unsigned char tmp90 = tmp85.size();
				auto tmp91 = reinterpret_cast<char*>(&tmp90);
				s += std::string(tmp91, sizeof(unsigned char));
				s += tmp85;
				
				s += tmp84.first;
				
				s += '\x01';
				int tmp93 = tmp84.second;
				auto tmp94 = reinterpret_cast<char*>(&tmp93);
				s += std::string(tmp94, sizeof(int));
			}
		}
		
		// serialize constants
		s += __has_constants;
		if (__has_constants)
		{
			s += __constants.serialize();
		}
		
		return s;
	}
	
	unsigned int deserialize(const std::string &s, unsigned int offset=0)
	{
		// deserialize board
		__has_board = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_board)
		{
			unsigned char tmp95;
			tmp95 = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
			std::string tmp96 = std::string(&s[offset], tmp95);
			offset += tmp95;
			while (tmp96.size() < sizeof(unsigned int))
				tmp96 += '\x00';
			unsigned int tmp97;
			tmp97 = *((unsigned int*) (&tmp96[0]));
			
			__board.clear();
			for (unsigned int tmp98 = 0; tmp98 < tmp97; tmp98++)
			{
				std::vector<ECell> tmp99;
				offset++;
				unsigned char tmp100;
				tmp100 = *((unsigned char*) (&s[offset]));
				offset += sizeof(unsigned char);
				std::string tmp101 = std::string(&s[offset], tmp100);
				offset += tmp100;
				while (tmp101.size() < sizeof(unsigned int))
					tmp101 += '\x00';
				unsigned int tmp102;
				tmp102 = *((unsigned int*) (&tmp101[0]));
				
				tmp99.clear();
				for (unsigned int tmp103 = 0; tmp103 < tmp102; tmp103++)
				{
					ECell tmp104;
					offset++;
					char tmp105;
					tmp105 = *((char*) (&s[offset]));
					offset += sizeof(char);
					tmp104 = (ECell) tmp105;
					tmp99.push_back(tmp104);
				}
				__board.push_back(tmp99);
			}
		}
		
		// deserialize agents
		__has_agents = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_agents)
		{
			unsigned char tmp106;
			tmp106 = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
			std::string tmp107 = std::string(&s[offset], tmp106);
			offset += tmp106;
			while (tmp107.size() < sizeof(unsigned int))
				tmp107 += '\x00';
			unsigned int tmp108;
			tmp108 = *((unsigned int*) (&tmp107[0]));
			
			__agents.clear();
			for (unsigned int tmp109 = 0; tmp109 < tmp108; tmp109++)
			{
				std::string tmp110;
				offset++;
				unsigned char tmp112;
				tmp112 = *((unsigned char*) (&s[offset]));
				offset += sizeof(unsigned char);
				std::string tmp113 = std::string(&s[offset], tmp112);
				offset += tmp112;
				while (tmp113.size() < sizeof(unsigned int))
					tmp113 += '\x00';
				unsigned int tmp114;
				tmp114 = *((unsigned int*) (&tmp113[0]));
				
				tmp110 = s.substr(offset, tmp114);
				offset += tmp114;
				
				Agent tmp111;
				offset++;
				offset = tmp111.deserialize(s, offset);
				
				__agents[tmp110] = tmp111;
			}
		}
		
		// deserialize scores
		__has_scores = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_scores)
		{
			unsigned char tmp115;
			tmp115 = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
			std::string tmp116 = std::string(&s[offset], tmp115);
			offset += tmp115;
			while (tmp116.size() < sizeof(unsigned int))
				tmp116 += '\x00';
			unsigned int tmp117;
			tmp117 = *((unsigned int*) (&tmp116[0]));
			
			__scores.clear();
			for (unsigned int tmp118 = 0; tmp118 < tmp117; tmp118++)
			{
				std::string tmp119;
				offset++;
				unsigned char tmp121;
				tmp121 = *((unsigned char*) (&s[offset]));
				offset += sizeof(unsigned char);
				std::string tmp122 = std::string(&s[offset], tmp121);
				offset += tmp121;
				while (tmp122.size() < sizeof(unsigned int))
					tmp122 += '\x00';
				unsigned int tmp123;
				tmp123 = *((unsigned int*) (&tmp122[0]));
				
				tmp119 = s.substr(offset, tmp123);
				offset += tmp123;
				
				int tmp120;
				offset++;
				tmp120 = *((int*) (&s[offset]));
				offset += sizeof(int);
				
				__scores[tmp119] = tmp120;
			}
		}
		
		// deserialize constants
		__has_constants = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_constants)
		{
			offset = __constants.deserialize(s, offset);
		}
		
		return offset;
	}
};

} // namespace models

} // namespace ks

#endif // _KS_MODELS_H_
