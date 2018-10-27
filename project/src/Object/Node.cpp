#include "Node.h"

Node::Node(const std::string& name, State state)
	:
	name_(name),
	state_(state),
	priority_(0.f),
	sleepCnt_(0),
	hierarchy_(1)
{
	initID();
}

Node::~Node() {
	deleteChildren();
}

Node * Node::selfPtr() const {
	return selfPtr_;
}

void Node::setSelfPtr(Node * selfPtr) {
	selfPtr_ = selfPtr;
}

Node* Node::getParentPtr() const {
	return parentPtr_;
}

void Node::setParentPtr(Node * parentPtr) {
	parentPtr_ = parentPtr;
}

Node * Node::getRootPtr() const {
	Node* parent = getParentPtr();
	if (!parent) { return selfPtr_; }
	else { return parent->getRootPtr(); }
}

std::vector<Node*> Node::getChildren() const {
	std::vector<Node*> ret;
	for (auto child : children_) {
		//���g�̎q�����m��
		ret.push_back(child);
		//���ȍ~�̃I�u�W�F�N�g���m��
		auto temp = child->getChildren();
		ret.insert(ret.end(), temp.begin(), temp.end());
	}
	return ret;
}

bool Node::findObject(Node* object, const std::vector<std::string>& findNames, const std::vector<std::string>& findNotNames) const {
	for (auto& name : findNames) {
		//�܂ނׂ����O���܂ރI�u�W�F�N�g��������Ȃ�������continue
		if (!object->findName(name)) { continue; }
		for (auto& notName : findNotNames) {
			//�܂܂�Ȃ����O���܂܂�Ă�����false
			if (object->findName(notName)) {
				return false;
			}
		}
		return true;
	}
	return false;
}

std::vector<Node*> Node::getObjectsFromChildren(const std::vector<std::string>& findNames, const std::vector<std::string>& findNotNames) const {
	std::vector<Node*> ret;
	for (auto child : children_) {
		//���ȍ~�ɂ��Ă�����
		auto r = child->getObjectsFromChildren(findNames, findNotNames);
		ret.insert(ret.end(), r.begin(), r.end());
		//�q���������Ɉ�v����Ȃ�m��
		if (findObject(child, findNames, findNotNames)) {
			ret.push_back(child);
		}
	}
	return std::vector<Node*>();
}

std::vector<Node*> Node::getObjectsFromRoot(const std::vector<std::string>& findNames, const std::vector<std::string>& findNotNames) const {
	auto root = getRootPtr();
	auto ret = root->getObjectsFromChildren(findNames, findNotNames);
	return ret;
}

Node* Node::getObjectFromChildren(const std::string& name) const {
	for (auto child : children_) {
		//�q���������𖞂����Ă���Ύq����Ԃ�
		if (child->name() == name) { return child; }
		//���ȍ~�̌����A������΂����Ԃ�
		auto temp = child->getObjectFromChildren(name);
		if (temp) { return temp; }
	}
	return nullptr;
}

Node* Node::getObjectFromRoot(const std::string& name) const {
	auto root = getRootPtr();
	return root->getObjectFromChildren(name);
}

Node* Node::getObjectFromChildren(int id) const {
	//�����ƈ�v���Ă����玩����Ԃ�
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

bool Node::matchingName(const std::string & name) const {
	return (name == name_);
}

bool Node::findName(const std::string & name) const {
	return (name_.find(name) != std::string::npos);
}

std::string Node::changeName(const std::string& name) {
	std::string oldname = name_;
	name_ = name;
	return oldname;
}

void Node::appendName(const std::string& append) {
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

void Node::killFromChildren(const std::string& name) {
	for (auto child : children_) {
		if (child->name() == name) {
			child->kill();
		}
	}
}

void Node::killFromRoot(const std::string& name) {
	auto root = getRootPtr();
	root->killFromChildren(name);
}

void Node::killObjectsFromChildren(const std::vector<std::string>& findNames, const std::vector<std::string>& findNotNames) {
	for (auto child : children_) {
		if (findObject(child, findNames, findNotNames)) {
			child->kill();
		}
	}
}

void Node::killObjectsFromRoot(const std::vector<std::string>& findNames, const std::vector<std::string>& findNotNames) {
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

void Node::runFromChildren(const std::string& name) {
	run();
	for (auto child : children_) {
		if (child->name() == name) {
			child->run();
		}
	}
}

void Node::runFromRoot(const std::string& name) {
	auto root = getRootPtr();
	root->runFromChildren(name);
}

void Node::runObjectsFromChildren(const std::vector<std::string>& findNames, const std::vector<std::string>& findNotNames) {
	for (auto child : children_) {
		if (findObject(child, findNames, findNotNames)) {
			child->run();
		}
	}
}

void Node::runObjectsFromRoot(const std::vector<std::string>& findNames, const std::vector<std::string>& findNotNames) {
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

void Node::stopFromChildren(const std::string& name) {
	stop();
	for (auto child : children_) {
		if (child->name() == name) {
			child->stop();
		}
	}
}

void Node::stopFromRoot(const std::string& name) {
	auto root = getRootPtr();
	root->stopFromChildren(name);
}

void Node::stopObjectsFromChildren(const std::vector<std::string>& findNames, const std::vector<std::string>& findNotNames) {
	stop();
	for (auto child : children_) {
		if (findObject(child, findNames, findNotNames)) {
			child->stop();
		}
	}
}

void Node::stopObjectsFromRoot(const std::vector<std::string>& findNames, const std::vector<std::string>& findNotNames) {
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

void Node::sleepFromChildren(const std::string & name, int sleepCnt) {
	sleep(sleepCnt);
	for (auto child : children_) {
		if (child->name() == name) {
			child->sleep(sleepCnt);
		}
	}
}

void Node::sleepFromRoot(const std::string & name, int sleepCnt) {
	auto root = getRootPtr();
	root->sleepFromChildren(name, sleepCnt);
}

void Node::sleepObjectsFromChildren(const std::vector<std::string>& findNames, const std::vector<std::string>& findNotNames, int sleepCnt) {
	sleep(sleepCnt);
	for (auto child : children_) {
		if (findObject(child, findNames, findNotNames)) {
			child->sleep(sleepCnt);
		}
	}
}

void Node::sleepObjectsFromRoot(const std::vector<std::string>& findNames, const std::vector<std::string>& findNotNames, int sleepCnt) {
	auto root = getRootPtr();
	root->sleepObjectsFromChildren(findNames, findNotNames, sleepCnt);
}

void Node::resume() {
	state_ = State::Run;
}

int Node::ID() const {
	return id_;
}

float Node::priority() const {
	return priority_;
}

const std::string& Node::name() const {
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

void Node::changePriority(float priority) {
	priority_ = priority;
	//! �`��D��x���ύX�����Ƃ��Ƀ��[�g�̕`�揇�p�q���I�u�W�F�N�g���\�[�g
	getRootPtr()->sortByPriority();
}

int Node::receiveMsg(Node* sender, const std::string& msg) {
	return 0;
}

int Node::postMsg(Node* receiver, const std::string& msg) {
	if (!receiver) { return 0; }
	return receiver->receiveMsg(selfPtr(), msg);
}

void Node::initID() {
	++uid_;
	id_ = uid_;
}

void Node::init() {}

void Node::insert() {
	//! �ǉ�����I�u�W�F�N�g�������
	if (!insert_.empty()) {
		//! �q���ɒǉ�
		children_.insert(children_.end(),
			insert_.begin(),
			insert_.end());
		//! �`��p�q���I�u�W�F�N�g�ꗗ�ɂ��ǉ�
		childrenForRender_.insert(childrenForRender_.end(),
			insert_.begin(),
			insert_.end());
		//! init()�������ŌĂ�
		for (auto ins : insert_) {
			ins->init();
		}
		//! �ǉ����I������̂ŃN���A
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
	//�I�u�W�F�N�g�̍폜�E�ǉ�
	children_.erase(
		std::remove_if(children_.begin(), children_.end(), std::mem_fn(&Node::isDead)),
		children_.end()
	);
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

void Node::renderStop() {}

void Node::renderSleep() {}

void Node::renderDestroy() {}

void Node::renderChildObjects() {
	for (auto child : children_) {
		child->renderSelect();
	}
}

void Node::renderWithChildrenRun() {
	render();
	renderChildObjects();
}

void Node::renderWithChildrenStop() {
	renderStop();
	renderChildObjects();
}

void Node::renderWithChildrenSleep() {
	renderSleep();
	renderChildObjects();
}

void Node::renderWithChildrenDestroy() {
	renderDestroy();
	renderChildObjects();
}

void Node::renderSelect() {
	switch (state()) {
	case State::Run:
		renderWithChildrenRun();		break;
	case State::Stop:
		renderWithChildrenStop();		break;
	case State::Sleep:
		renderWithChildrenSleep();		break;
	case State::Destroy:
		renderWithChildrenDestroy();	break;
	}
}

void Node::renderWithChildren() {
	render();
	//! �`�揇�ɑΉ�����
	for (auto child : childrenForRender_) {
		child->renderSelf();
	}
}

void Node::sortByPriority() {
	std::sort(childrenForRender_.begin(), childrenForRender_.end(),
		[](Node* lhs, Node* rhs) {return lhs->priority() < rhs->priority(); });
}

void Node::renderSelf() {
	renderSelectSelf();
}

void Node::renderSelectSelf() {
	switch (state())
	{
	case State::Run:
		render();
		break;
	case State::Stop:
		renderStop();
		break;
	case State::Sleep:
		renderSleep();
		break;
	case State::Destroy:
		renderDestroy();
		break;
	}
}

void Node::deleteChildren() {
	for (auto child : children_) {
		delete child;
	}
}