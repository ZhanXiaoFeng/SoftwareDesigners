#include "pch.h"
#include "DesignPattern.h"


DesignPattern::DesignPattern()
{
}


DesignPattern::~DesignPattern()
{
}


/***********************************************************************
* ����ģʽ��Factory Pattern��
*/
namespace FactoryPattern
{
	// �ӿ���
	class Shape {
	public:
		virtual void draw() = 0;
	};

	// 3��ʵ����
	class Rectangle : public Shape {
	public:
		void draw() {
			cout << "This is a Rectangle! \n";
		}
	};
	class Circle : public Shape {
	public:
		void draw() {
			cout << "This is a Circle! \n";
		}
	};
	class Square : public Shape {
	public:
		void draw() {
			cout << "This is a Square! \n";
		}
	};

	// ������
	class ShapeFactory {
	public:
		Shape* getShape(const string &shapeType) {
			if (shapeType.compare("Rectangle") == 0) {
				return new Rectangle();
			}
			else if (shapeType.compare("Circle") == 0) {
				return new Circle();
			}
			else if (shapeType.compare("Square") == 0) {
				return new Square();
			}
			return nullptr;
		}
	};

	// ʹ�ù�������ȡʵ��
	FactoryPattern::FactoryPattern()
	{
		ShapeFactory factory;

		Shape *shape1 = factory.getShape("Rectangle");
		Shape *shape2 = factory.getShape("Circle");
		Shape *shape3 = factory.getShape("Square");
		shape1->draw();
		shape2->draw();
		shape3->draw();
	}
}


/***********************************************************************
* ����ģʽ��Singleton Pattern��
*/
namespace SingletonPattern
{
	SingletonPattern *SingletonPattern::m_instance = nullptr;

	SingletonPattern *SingletonPattern::getInstance()
	{
		if (nullptr == m_instance)
			m_instance = new SingletonPattern();
		return m_instance;
	}
	void SingletonPattern::release()
	{
		if (m_instance)
			delete m_instance;
		m_instance = nullptr;
	}
}


/***********************************************************************
* ������ģʽ��Builder Pattern��
*/
namespace BuilderPattern
{
	// ʳ���װ
	class Packing {
	public:
		virtual string pack() = 0;
	};
	class Wrapper : public Packing {
	public:
		string pack() { return "Wrapper"; }
	};
	class Bottle : public Packing {
	public:
		string pack() { return "Bottle"; }
	};

	// ʳ����Ŀ
	class Item {
	public:
		virtual string name() = 0;
		virtual Packing* packing() = 0;
		virtual float price() = 0;
	};
	// ʳ����ݰ�װ����
	class Burger : public Item {
	public:
		Packing* packing() {
			return new Wrapper;
		}
	};
	class Drink : public Item {
	public:
		Packing* packing() {
			return new Bottle;
		}
	};

	// ��������
	class VegBurger : public Burger {
	public:
		string name() {
			return "VegBurger";
		}
		float price() {
			return 12.5f;
		}
	};
	class ChickenBurger : public Burger {
	public:
		string name() {
			return "ChickenBurger";
		}
		float price() {
			return 25.0f;
		}
	};
	class Coke :public Drink {
	public:
		string name() {
			return "Coke";
		}
		float price() {
			return 5.5f;
		}
	};
	class Pepsi :public Drink {
	public:
		string name() {
			return "Pepsi";
		}
		float price() {
			return 6.5f;
		}
	};

	// �����ϲ�Ʒ�����ײʹ���
	class Meal {
	public:
		void addItem(Item *item) {
			items_.push_back(item);
		}		
		float getCose() {
			float cost = 0.0f;
			for (auto item : items_)
				cost += item->price();
			return cost;
		}
		void showItems() {
			for (auto item : items_) {
				cout << "Item :" << item->name() << endl;
				cout << "Pack :" << item->packing()->pack() << endl;
				cout << "Price:" << item->price() << endl;
			}
		}
	private:
		vector<Item *> items_;
	};

	// ��builder����Meal
	class MealBuilder {
	public:
		Meal *prepareVegMeal() {
			Meal *meal = new Meal;
			meal->addItem(new VegBurger);
			meal->addItem(new Coke);
			return meal;
		}
		Meal *prepareNonVegMeal() {
			Meal *meal = new Meal;
			meal->addItem(new ChickenBurger);
			meal->addItem(new Pepsi);
			return meal;
		}
	};

	BuilderPattern::BuilderPattern()
	{
		MealBuilder builder;
		Meal *mealA = builder.prepareVegMeal();
		Meal *mealB = builder.prepareNonVegMeal();
		mealA->showItems();
		mealB->showItems();
	}
}








/***********************************************************************
* �Ž�ģʽ��Bridge Pattern��
*/
namespace BridgePattern
{
	// �Žӽӿ�
	class DrawAPI {
	public:
		virtual void drawCircle(int r) = 0;
	};

	// �Ž�ʵ����
	class RedCircle : public DrawAPI {
	public: 
		void drawCircle(int r) {
			cout << "draw red circle r = " << r << endl;
		}
	};
	class GreenCircle : public DrawAPI {
	public:
		void drawCircle(int r) {
			cout << "draw green circle r = " << r << endl;
		}
	};

	// ʹ�� DrawAPI �ӿڴ���������
	class Shape {
	public:
		Shape(DrawAPI *api) {
			drawAPI_ = api;
		}
		virtual void draw() = 0;
	protected:
		DrawAPI *drawAPI_;
	};

	// ʵ����
	class Circle : public Shape {
	public:
		Circle(int r, DrawAPI *api) : Shape(api) {
			r_ = r;
		}
		void draw() {
			drawAPI_->drawCircle(r_);
		}
	protected:
		int r_;
	};

	BridgePattern::BridgePattern()
	{
		Shape *redCircle = new Circle(100, new RedCircle());
		Shape *greenCircle = new Circle(100,  new GreenCircle());
		redCircle->draw();
		greenCircle->draw();
	}
}


/***********************************************************************
* ������ģʽ��Filter Pattern�����׼ģʽ��Criteria Pattern��
*/ 
namespace FilterPattern
{
	// �ڸ����ϴ�����׼
	class Person {
	public:
		Person(string name, string gender, string status) {
			name_ = name;
			gender_ = gender;
			maritalStatus_ = status;
		}
		// ͵����public
		string name_;
		string gender_;
		string maritalStatus_;
	};

	// Ϊ��׼�����ӿ�
	class Criteria {
	public:
		virtual vector<Person> meetCriteria(const vector<Person> &persons) = 0;
	};

	// �ӿڵ�ʵ���࣬���ֹ�������ʵ��
	class CriteriaMale : public Criteria {
	public:
		vector<Person> meetCriteria(const vector<Person> &persons) {
			vector<Person> malePersons;
			for (const auto &person : persons) {
				if (person.gender_ == "MALE")
					malePersons.push_back(person);
			}
			return malePersons;
		}
	};
	class CriteriaFemale : public Criteria {
	public:
		vector<Person> meetCriteria(const vector<Person> &persons) {
			vector<Person> malePersons;
			for (const auto &person : persons) {
				if (person.gender_ == "FEMALE")
					malePersons.push_back(person);
			}
			return malePersons;
		}
	};
	class CriteriaSingle : public Criteria {
	public:
		vector<Person> meetCriteria(const vector<Person> &persons) {
			vector<Person> malePersons;
			for (const auto &person : persons) {
				if (person.maritalStatus_ == "SINGLE")
					malePersons.push_back(person);
			}
			return malePersons;
		}
	};

	FilterPattern::FilterPattern()
	{
		vector<Person> persons = {
			Person("Robert","Male", "Single"),
			Person("John","Male", "Married"),
			Person("Laura","Female", "Married"),
			Person("Diana","Female", "Single"),
			Person("Mike","Male", "Single"),
			Person("Bobby","Male", "Single")
		};

		Criteria *male = new CriteriaMale();
		Criteria *female = new CriteriaFemale();
		Criteria *single = new CriteriaSingle();
	}
}


/***********************************************************************
* ���ģʽ��Composite Pattern��
*/
namespace CompositePattern
{
	class Employee {
	public:
		Employee(string name, string dept, int salary) {
			name_ = name;
			dept_ = dept;
			salary_ = salary;
		}
		void add(Employee *epl) {
			subordinates_.push_back(epl);
		}
		// ͵��
		string name_;
		string dept_;
		int salary_;
		vector<Employee *> subordinates_;
	};

	CompositePattern::CompositePattern()
	{
		Employee *CEO = new Employee("John", "CEO", 30000);

		Employee *headSales = new Employee("Robert", "Head Sales", 20000);
		Employee *headMarketing = new Employee("Michel", "Head Marketing", 20000);

		Employee *clerk1 = new Employee("Laura", "Marketing", 10000);
		Employee *clerk2 = new Employee("Bob", "Marketing", 10000);
		Employee *salesExecutive1 = new Employee("Richard", "Sales", 10000);
		Employee *salesExecutive2 = new Employee("Rob", "Sales", 10000);

		CEO->add(headSales);
		CEO->add(headMarketing);

		headSales->add(salesExecutive1);
		headSales->add(salesExecutive2);

		headMarketing->add(clerk1);
		headMarketing->add(clerk2);
	}
}

/***********************************************************************
* װ����ģʽ��Decorator Pattern��
*/
namespace DecoratorPattern
{
	// ��ͨ����
	class Shape {
	public: 
		virtual void draw() = 0;
	};
	class Rectangle : public Shape {
	public:
		void draw() {
			cout << "Rectangle" << endl;
		}
	};
	class Circle : public Shape {
	public:
		void draw() {
			cout << "Circle" << endl;
		}
	};

	// װ�γ�����
	class ShapeDecorator : public Shape {
	public:
		ShapeDecorator(Shape *shape) {
			shape_ = shape;
		}
		void draw() {
			shape_->draw();
		}
	protected:
		Shape *shape_;
	};
	// ��չʵ����
	class RedShapeDecorator : public ShapeDecorator {
	public:
		RedShapeDecorator(Shape *shape) : ShapeDecorator(shape) {
			;
		}
		void draw() {
			ShapeDecorator::draw();
			cout << "draw red" << endl;
		}
	};

	DecoratorPattern::DecoratorPattern()
	{
		Shape *circle = new Circle;
		Shape *redRectangle = new RedShapeDecorator(new Rectangle);
		Shape *redCircle = new RedShapeDecorator(new Circle);

		circle->draw();
		redRectangle->draw();
		redCircle->draw();
	}
}


/***********************************************************************
* ��Ԫģʽ��Flyweight Pattern��
*/
namespace FlyweightPattern
{
	class Shape {
	public: 
		virtual void draw() = 0;
	};
	class Circle : public Shape {
	public:
		Circle(string color) {
			color_ = color;
		}
		void draw() {
			cout << "color : " << color_ << endl;
		}
	private:
		string color_;
	};

	// ������ά��һ��map
	class ShapeFactory {
	public:
		Shape *getCircle(string color) {
			auto ite = circleMap_.find(color);
			if (ite != circleMap_.end())
				return (*ite).second;
			Shape *circle = new Circle(color);
			circleMap_[color] = circle;
			return circle;
		}
	private:
		map<string, Shape*> circleMap_;
	};

	FlyweightPattern::FlyweightPattern()
	{
		ShapeFactory factory;
		Shape *circle1 = factory.getCircle("red");
		Shape *circle2 = factory.getCircle("red");
		Shape *circle3 = factory.getCircle("red");
		Shape *circle4 = factory.getCircle("green");
		Shape *circle5 = factory.getCircle("green");
		Shape *circle6 = factory.getCircle("green");
		circle1->draw();
		circle2->draw();
		circle3->draw();
		circle4->draw();
	}
}





/***********************************************************************
* ������ģʽ��Chain of Responsibility Pattern��
*/
namespace CORPattern
{
	class AbstractLogger {
	public:
		enum log_level {
			INFO = 1,
			DEBUG,
			ERROR
		};
		void setNextLogger(AbstractLogger *loger) {
			nextLogger_ = loger;
		}
		void logMessage(log_level level, string msg) {
			if (nextLogger_ != nullptr) {
				nextLogger_->logMessage(level, msg);
			}
		}
	private:
		AbstractLogger *nextLogger_;
	};

	CORPattern::CORPattern()
	{
		// ����˳��ִ�У�����û�����ֳ���������ܴ���ʹ�����һ����
	}
}


/***********************************************************************
* �н���ģʽ��Mediator Pattern��
*/
namespace MediatorPattern
{
	class User {
	public:
		User(string name) : name_(name) {
		
		}
		string name_;
	};

	// �н���
	class ChatRoom {
	public:
		static void showMessage(User *user, string msg) {
			cout << user->name_ << " say : " << msg << endl;
		}
	};

	class ChatMember : public User{
	public:
		ChatMember(string name) : User(name) {
		
		}
		void showMessage(string msg) {
			ChatRoom::showMessage(this, msg);
		}
	};

	MediatorPattern::MediatorPattern()
	{
		ChatMember *member = new ChatMember("Tom");
		member->showMessage("Hello world!");
	}
}


/***********************************************************************
* ����¼ģʽ��Memento Pattern��
*/
namespace MementoPattern
{
	// ����Ʒ--����������
	class Memento {
	public:
		Memento(string state) {
			state_ = state;
		}
		string getState() {
			return state_;
		}
	private:
		string state_;
	};

	// ������--ӵ������
	class Originator {
	public:
		void setState(string state) {
			state_ = state;
		}
		string getState() {
			return state_;
		}
		Memento *saveStateToMemento() {
			return new Memento(state_);
		}
		void getStateFromMemento(Memento *memento) {
			state_ = memento->getState();
		}
	private:
		string state_;
	};

	// ������--��������
	class CareTaker {
	public:
		void add(Memento *memento) {
			vMementos_.push_back(memento);
		}
		Memento *get(int index) {
			return vMementos_[index];
		}
	private:
		vector<Memento *> vMementos_;
	};

	MementoPattern::MementoPattern()
	{
		Originator originator;
		CareTaker careTaker;
		originator.setState("State #1");
		originator.setState("State #2");
		careTaker.add(originator.saveStateToMemento());
		originator.setState("State #3");
		careTaker.add(originator.saveStateToMemento());
		originator.setState("State #4");

		cout << ("Current State: " + originator.getState());
		originator.getStateFromMemento(careTaker.get(0));
		cout << ("First saved State: " + originator.getState());
		originator.getStateFromMemento(careTaker.get(1));
		cout << ("Second saved State: " + originator.getState());
	}
}


/***********************************************************************
* �۲���ģʽ��Observer Pattern��
*/
namespace ObserverPattern
{
	// �۲��߽ӿ�
	class Observer {
	public:
		virtual void update() = 0;
	};

	// �۲����
	class Subject {
	public:
		void setState(string state) {
			state_ = state;
		}
		string getState() {
			return state_;
		}
		void attach(Observer *observer) {
			vcObservers_.push_back(observer);
		}
		void notifyAllObservers() {
			for (Observer *observer : vcObservers_) {
				observer->update();
			}
		}
	private:
		string state_;
		vector<Observer*> vcObservers_;
	};

	// �����۲��� TODO
	class ObserverOne : public Observer {};
	class ObserverTwo : public Observer {};
	class ObserverTre : public Observer {};

	ObserverPattern::ObserverPattern()
	{
		// ÿ��Subject���£�����update���й۲���
	}
}


/***********************************************************************
* ״̬ģʽ��State Pattern��
*/
namespace StatePattern
{
	class Context;

	class State {
	public:
		virtual void doAction(Context *context) = 0;
		virtual string toString() = 0;
	};

	class StartState : public State {
	public:
		void doAction(Context *context) { context->setState(this); }
		string toString() { return "Start State"; }
	};
	class StopState : public State {
	public:
		void doAction(Context *context) { context->setState(this); }
		string toString() { return "Stop State"; }
	};

	// ʹ�� Context ���鿴��״̬ State �ı�ʱ����Ϊ�仯
	class Context {
	public:
		void setState(State *state) { state_ = state; }
		State *getState() { return state_; }
		State *state_;
	};

	StatePattern::StatePattern()
	{
		Context *context = new Context;

		StartState *startState = new StartState();
		startState->doAction(context);

		cout << "Current State : " << context->getState()->toString() << endl;

		StopState *stopState = new StopState();
		stopState->doAction(context);

		cout << "Current State : " << context->getState()->toString() << endl;
	}
}


/***********************************************************************
* �ն���ģʽ��Null Object Pattern��
*/
namespace NullObjectPattern
{
	class AbstractCustomer {
	public:
		virtual string getName() = 0;
		virtual bool isNull() = 0;
	protected:
		string name_;
	};

	class RealCustomer :public AbstractCustomer {
	public:
		RealCustomer(string name) { name_ = name; }
		string getName() { return name_; }
		bool isNull() { return false; }
	};
	class NullCustomer :public AbstractCustomer {
	public:
		string getName() { return "Not Available in Customer Database"; }
		bool isNull() { return true; }
	};

	class CustomerFactory {
	public:
		set<string> vcCustomers;
		CustomerFactory() {
			vcCustomers.insert("Rob");
			vcCustomers.insert("Joe");
			vcCustomers.insert("julie");
		}
		AbstractCustomer* getCustomer(string name) {
			auto ite = vcCustomers.find(name);
			if (ite != vcCustomers.end()) {
				return new RealCustomer(name);
			}
			return new NullCustomer();
		}
	};

	NullObjectPattern::NullObjectPattern()
	{
		CustomerFactory factory;
		AbstractCustomer *customer1 = factory.getCustomer("Rob");
		AbstractCustomer *customer2 = factory.getCustomer("Bob");
		AbstractCustomer *customer3 = factory.getCustomer("Julie");
		AbstractCustomer *customer4 = factory.getCustomer("Laura");
		cout << customer1->getName();
		cout << customer2->getName();
		cout << customer3->getName();
		cout << customer4->getName();
	}
}



/***********************************************************************
* ����ģʽ��Strategy Pattern��
*/
namespace StrategyPattern
{
	class Strategy {
	public:
		virtual int doOperation(int num1, int num2) = 0;
	};

	class OperationAdd : public Strategy {
		int doOperation(int num1, int num2) { return num1 + num2; }
	};
	class OperationSubstract : public Strategy {
		int doOperation(int num1, int num2) { return num1 - num2; }
	};
	class OperationMultiply : public Strategy {
		int doOperation(int num1, int num2) { return num1 * num2; }
	};

	class Context {
	public:
		Context(Strategy *strategy) { strategy_ = strategy; }
		int executeStrategy(int num1, int num2) { return strategy_->doOperation(num1, num2); }
	private:
		Strategy *strategy_;
	};

	StrategyPattern::StrategyPattern()
	{
		Context *context = new Context(new OperationAdd());
		cout << "10 + 5 = " << context->executeStrategy(10, 5);

		Context *context = new Context(new OperationSubstract());
		cout << "10 - 5 = " << context->executeStrategy(10, 5);

		Context *context = new Context(new OperationMultiply());
		cout << "10 * 5 = " << context->executeStrategy(10, 5);
	}
}


/***********************************************************************
* ģ��ģʽ��Template Pattern��
*/
namespace TemplatePattern
{
	class Game {
	public:
		virtual void initialize() = 0;
		virtual void startPlay() = 0;
		virtual void endPlay() = 0;
		void play() {
			initialize();
			startPlay();
			endPlay();
		}
	};

	class Cricket : public Game {
	public:
		void initialize() { cout << "Cricket Init!\n"; }
		void startPlay() { cout << "Cricket Start!\n"; }
		void endPlay() { cout << "Cricket End!\n"; }
	};
	class Football : public Game {
	public:
		void initialize() { cout << "Football Init!\n"; }
		void startPlay() { cout << "Football Start!\n"; }
		void endPlay() { cout << "Football End!\n"; }
	};

	TemplatePattern::TemplatePattern()
	{
	}
}