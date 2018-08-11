#include "Node.h"

Node::Node(const string& name, State state)
	:
	name_(name),
	state_(state),
	priority_(0.f),
	sleepCnt_(0),
	hierarchy_(1)
{
	initID();
}

Node::~Node() {}

Node * Node::selfPtr() const {
	return selfPtr_;
}

void Node::setSelfPtr(Node * selfPtr) {
	selfPtr_ = selfPtr;
}

Node * Node::getParentPtr() const {
	return parentPtr_;
}

void Node::setParentPtr(Node * parentPtr) {
	parentPtr_ = parentPtr;
}

Node * Node::getRootPtr() const {
	Node* parent = getParentPtr();
	if (!parent) { return selfPtr_; }
	else { return getRootPtr(); }
}

vector<Node*> Node::getChildren() const {
	vector<Node*> ret;
	for (auto child : children_) {
		//自身の子供を確保
		ret.push_back(child);
		//孫以降のオブジェクトも確保
		auto temp = child->getChildren();
		ret.insert(ret.end(), temp.begin(), temp.end());
	}
	return ret;
}

bool Node::findObject(Node* object, const vector<string>& findNames, const vector<string>& findNotNames) const {
	for (auto& name : findNames) {
		//含むべき名前を含むオブジェクトが見つからなかったらcontinue
		if (!object->findName(name)) { continue; }
		for (auto& notName : findNotNames) {
			//含まれない名前が含まれていたらfalse
			if (object->findName(notName)) {
				return false;
			}
		}
		return true;
	}
	return false;
}

vector<Node*> Node::getObjectsFromChildren(const vector<string>& findNames, const vector<string>& findNotNames) const {
	vector<Node*> ret;
	for (auto child : children_) {
		//孫以降についても検索
		auto r = child->getObjectsFromChildren(findNames, findNotNames);
		ret.insert(ret.end(), r.begin(), r.end());
		//子供が条件に一致するなら確保
		if (findObject(child, findNames, findNotNames)) {
			ret.push_back(child);
		}
	}
	return vector<Node*>();
}

vector<Node*> Node::getObjectsFromRoot(const vector<string>& findNames, const vector<string>& findNotNames) const {
	auto root = getRootPtr();
	auto ret = root->getObjectsFromChildren(findNames, findNotNames);
	return ret;
}

Node* Node::getObjectFromChildren(const string& name) const {
	for (auto child : children_) {
		//子供が条件を満たしていれば子供を返す
		if (child->name() == name) { return child; }
		//孫以降の検索、見つかればそれを返す
		auto temp = child->getObjectFromChildren(name);
		if (temp) { return temp; }
	}
	return nullptr;
}

Node* Node::getObjectFromRoot(const string& name) const {
	auto root = getRootPtr();
	return root->getObjectFromChildren(name);
}

Node* Node::getObjectFromChildren(int id) const {
	//自分と一致していたら自分を返す
	if (ID() == id) { return selfPtr(); }
	for (auto child : children_) {
		if (child->ID() == id) { return child; }
		auto temp = child->getObjectFromChildren(id);
		if (temp) { return temp; }
	}
	return nullptr;
}

Node* Node::getObjectFromRoot(int id) const {
	auto root = getRootPtr();
	return root->getObjectFromChildren(id);
}

bool Node::matchingName(const string & name) const {
	return (name == name_);
}

bool Node::findName(const string & name) const {
	return (name_.find(name) != string::npos);
}

string Node::changeName(const string& name) {
	string oldname = name_;
	name_ = name;
	return oldname;
}

void Node::appendName(const string& append) {
	name_ += append;
}

bool Node::matchingID(int id) const {
	return id_ == id;
}

bool Node::isSame(Node* obj) const {
	if (!obj) { return false; }
	return id_ == obj->ID();
}

void Node::kill() {
	state_ = State::Destroy;
	for (auto child : children_) {
		child->kill();
	}
}

void Node::killFromChildren(const string& name) {
	for (auto child : children_) {
		if (child->name() == name) {
			child->kill();
		}
	}
}

void Node::killFromRoot(const string& name) {
	auto root = getRootPtr();
	root->killFromChildren(name);
}

void Node::killObjectsFromChildren(const vector<string>& findNames, const vector<string>& findNotNames) {
	for (auto child : children_) {
		if (findObject(child, findNames, findNotNames)) {
			child->kill();
		}
	}
}

void Node::killObjectsFromRoot(const vector<string>& findNames, const vector<string>& findNotNames) {
	auto root = getRootPtr();
	root->killObjectsFromChildren(findNames, findNotNames);
}

void Node::run() {
	state_ = State::Run;
}

void Node::runAll() {
	run();
	for (auto child : children_) {
		child->run();
	}
}

void Node::runFromChildren(const string& name) {
	run();
	for (auto child : children_) {
		if (child->name() == name) {
			child->run();
		}
	}
}

void Node::runFromRoot(const string& name) {
	auto root = getRootPtr();
	root->runFromChildren(name);
}

void Node::runObjectsFromChildren(const vector<string>& findNames, const vector<string>& findNotNames) {
	for (auto child : children_) {
		if (findObject(child, findNames, findNotNames)) {
			child->run();
		}
	}
}

void Node::runObjectsFromRoot(const vector<string>& findNames, const vector<string>& findNotNames) {
	auto root = getRootPtr();
	root->runObjectsFromChildren(findNames, findNotNames);
}

void Node::stop() {
	state_ = State::Stop;
}

void Node::stopAll() {
	stop();
	for (auto child : children_) {
		child->stop();
	}
}

void Node::stopFromChildren(const string& name) {
	stop();
	for (auto child : children_) {
		if (child->name() == name) {
			child->stop();
		}
	}
}

void Node::stopFromRoot(const string& name) {
	auto root = getRootPtr();
	root->stopFromChildren(name);
}

void Node::stopObjectsFromChildren(const vector<string>& findNames, const vector<string>& findNotNames) {
	stop();
	for (auto child : children_) {
		if (findObject(child, findNames, findNotNames)) {
			child->stop();
		}
	}
}

void Node::stopObjectsFromRoot(const vector<string>& findNames, const vector<string>& findNotNames) {
	auto root = getRootPtr();
	root->stopObjectsFromChildren(findNames, findNotNames);
}

void Node::sleep(int sleepCnt) {
	state_ = State::Sleep;
	sleepCnt_ = sleepCnt;
}

void Node::sleepAll(int sleepCnt) {
	sleep(sleepCnt);
	for (auto child : children_) {
		child->sleep(sleepCnt);
	}
}

void Node::sleepFromChildren(const string & name, int sleepCnt) {
	sleep(sleepCnt);
	for (auto child : children_) {
		if (child->name() == name) {
			child->sleep(sleepCnt);
		}
	}
}

void Node::sleepFromRoot(const string & name, int sleepCnt) {
	auto root = getRootPtr();
	root->sleepFromChildren(name, sleepCnt);
}

void Node::sleepObjectsFromChildren(const vector<string>& findNames, const vector<string>& findNotNames, int sleepCnt) {
	sleep(sleepCnt);
	for (auto child : children_) {
		if (findObject(child, findNames, findNotNames)) {
			child->sleep(sleepCnt);
		}
	}
}

void Node::sleepObjectsFromRoot(const vector<string>& findNames, const vector<string>& findNotNames, int sleepCnt) {
	auto root = getRootPtr();
	root->sleepObjectsFromChildren(findNames, findNotNames, sleepCnt);
}

void Node::resume() {
	state_ = State::Run;
}

int Node::ID() const {
	return id_;
}

int Node::priority() const {
	return priority_;
}

const string& Node::name() const {
	return name_;
}

Node::State Node::state() const {
	return state_;
}

bool Node::isRunning() const {
	return (state_ == State::Run);
}

bool Node::isStop() const {
	return (state_ == State::Stop);
}

bool Node::isSleep() const {
	return (state_ == State::Sleep);
}

bool Node::isDestroy() const {
	return (state_ == State::Destroy);
}

bool Node::isDead() const {
	return (state_ == State::Dead);
}

void Node::changePriority(int priority) {
	priority_ = priority;
}

int Node::receiveMsg(Node* sender, const string& msg) {
	return 0;
}

int Node::postMsg(Node* receiver, const string& msg) {
	return receiver->receiveMsg(selfPtr(), msg);
}

void Node::initID() {
	++uid_;
	id_ = uid_;
}

void Node::init() {}

void Node::insert() {
	//! 追加するオブジェクトがあれば
	if (!insert_.empty()) {
		//! 子供に追加
		children_.insert(children_.end(),
			insert_.begin(),
			insert_.end());
		//! init()もここで呼ぶ
		for (auto ins : insert_) {
			ins->init();
		}
		//! 追加が終わったのでクリア
		insert_.clear();
	}
}

void Node::update() {}

void Node::updateStop() {}

void Node::updateSleep() {}

void Node::updateDestroy() {}

void Node::updateChildObjects() {
	for (auto child : children_) {
		child->updateSelect();
	}
	//オブジェクトの削除・追加
	children_.erase(
		std::remove_if(children_.begin(), children_.end(), std::mem_fn(&Node::isDead)),
		children_.end());
	insert();
}

void Node::updateWithChildrenRun() {
	update();
	updateChildObjects();
}

void Node::updateWithChildrenStop() {
	updateStop();
	updateChildObjects();
}

void Node::updateWithChildrenSleep() {
	updateSleep();
	updateChildObjects();
}

void Node::updateWithChildrenDestroy() {
	updateDestroy();
	updateChildObjects();
}

void Node::updateSelect() {
	switch (state()) {
	case State::Run:
		updateWithChildrenRun();		break;
	case State::Stop:
		updateWithChildrenStop();		break;
	case State::Sleep:
		updateWithChildrenSleep();		break;
	case State::Destroy:
		updateWithChildrenDestroy();	break;
	}
}

void Node::updateWithChildren() {
	update();
	updateChildObjects();
}

void Node::render() {}

void Node::renderStop() {
	render();
}

void Node::renderSleep() {
	render();
}

void Node::renderDestroy() {}

void Node::renderChildObjects() {
	render();
}

void Node::renderWithChildrenRun()
{
}

void Node::renderWithChildrenStop()
{
}

void Node::renderWithChildrenSleep()
{
}

void Node::renderWithChildrenDestroy()
{
}

void Node::renderSelect()
{
}

void Node::renderWithChildren()
{
}
