/**
* @file Node.h
* @brief �S�ẴI�u�W�F�N�g�̊��N���X���`
* @detail �e�q�֌W�\�z�A���g�̋쓮��ԁA���b�Z�[�W����M�@�\������
* @date 2018.8.8�@�J�n
*/

#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <assert.h>
using namespace std;

/**
* @brief �S�ẴI�u�W�F�N�g�̊��N���X
*		 �e�q�֌W�\�z�A���g�̋쓮��Ԃ�����
*		 �쓮��Ԃɂ���ČĂяo���X�V�E�`�揈����ς���
*/
class Node
{
	/**
	* @brief  �쓮���
	*		�@��Ԃɉ����ČĂяo���X�V�E�`�揈����ς���
	*/
	enum class State {
		Non,		//����`
		Run,		//�ʏ�
		Stop,		//��~
		Sleep,		//�w��t���[�����Run�Ɉڍs
		Destroy,	//�폜�\��
		Dead,		//�폜�ς�
	};
public:
	//------------------------------------------------------
	//����
	//------------------------------------------------------
	Node(const string& name, State state);
	virtual ~Node();
	//------------------------------------------------------
	//�e�ɃI�u�W�F�N�g��ǉ�
	//------------------------------------------------------
	/** 
	* @brief �ʏ��ԂŐe�Ɏq����ǉ�
	* @param Ptr* obj �ǉ�����q���I�u�W�F�N�g�̃|�C���^
	* @return Node* �ǉ������q���I�u�W�F�N�g�̃|�C���^
	*/
	template<typename Ptr>
	Node* insertToParent(Ptr* obj);
	/**
	* @brief ��~��ԂŐe�Ɏq����ǉ�
	* @param Ptr* obj �ǉ�����q���I�u�W�F�N�g�̃|�C���^
	* @return Node* �ǉ������q���I�u�W�F�N�g�̃|�C���^
	*/
	template<typename Ptr>
	Node* insertToParentStop(Ptr* obj);
	/**
	* @brief Sleep��ԂŐe�Ɏq����ǉ�
	* @param Ptr* obj �ǉ�����q���I�u�W�F�N�g�̃|�C���^
	* @param int sleepCnt �Q������t���[����
	* @return Node* �ǉ������q���I�u�W�F�N�g�̃|�C���^
	*/
	template<typename Ptr>
	Node* insertToParentSleep(Ptr* obj, int sleepCnt);
	//------------------------------------------------------
	//�q�ɃI�u�W�F�N�g��ǉ�
	//------------------------------------------------------
	/**
	* @brief �ʏ��ԂŎq�ɃI�u�W�F�N�g��ǉ�
	* @param Ptr* obj �ǉ�����q���I�u�W�F�N�g�̃|�C���^
	* @return Node* �ǉ������q���I�u�W�F�N�g�̃|�C���^
	*/
	template<typename Ptr>
	Node* insertAsChild(Ptr* obj);
	/**
	* @brief ��~��ԂŎq�ɃI�u�W�F�N�g��ǉ�
	* @param Ptr* obj �ǉ�����q���I�u�W�F�N�g�̃|�C���^
	* @return Node* �ǉ������q���I�u�W�F�N�g�̃|�C���^
	*/
	template<typename Ptr>
	Node* insertAsChildStop(Ptr* obj);
	/**
	* @brief Sleep��ԂŎq�ɃI�u�W�F�N�g��ǉ�
	* @param Ptr* obj �ǉ�����q���I�u�W�F�N�g�̃|�C���^
	* @param int sleepCnt �Q������t���[����
	* @return Node* �ǉ������q���I�u�W�F�N�g�̃|�C���^
	*/
	template<typename Ptr>
	Node* insertAsChildSleep(Ptr* obj, int sleepCnt);
	//------------------------------------------------------
	//�|�C���^�֘A
	//------------------------------------------------------
	/** @brief ���g�̃|�C���^���擾���� */
	Node* selfPtr() const;
	/** @brief ���g�̃|�C���^��ݒ肷��(���[�g�ȊO�ŌĂԕK�v�͂Ȃ�) */
	void setSelfPtr(Node* selfPtr);
	/** @brief �e�̃|�C���^���擾���� */
	Node* getParentPtr() const;
	/** @brief �e�̃|�C���^��ݒ肷��(������) */
	void setParentPtr(Node* parentPtr);
	/** @brief ���[�g�I�u�W�F�N�g�̃|�C���^���擾���� */
	Node* getRootPtr() const;
	//------------------------------------------------------
	//�I�u�W�F�N�g�擾�֘A
	//------------------------------------------------------
	/** @brief �S�q���I�u�W�F�N�g���擾 */
	vector<Node*> getChildren() const;
	/**
	* @brief object�̖��O��findNames���܂܂�Ă��邩�AfindNotNames���܂܂�Ă��Ȃ��ꍇ��true��Ԃ�
	* @param Node* object ���ׂ�Ώۂ̃I�u�W�F�N�g�̃|�C���^
	* @param vector<string> findNames �܂܂�閼�O��vector
	* @param vector<string> findNotNames �܂܂�Ȃ����O��vector
	* @return bool object�̖��O��findNames���܂܂�Ă��邩�AfindNotNames���܂܂�Ă��Ȃ��ꍇ��true
	*/
	bool findObject(Node* object, const vector<string>& findNames, const vector<string>& findNotNames) const;
	/**
	* @brief �q���I�u�W�F�N�g����AfindNames���܂܂�Ă��邩�AfindNotNames���܂܂�Ă��Ȃ��I�u�W�F�N�g�̃|�C���^���擾����
	* @param vector<string> findNames �܂܂�閼�O��vector
	* @param vector<string> findNotNames �܂܂�Ȃ����O��vector
	* @return vector<Node*> ���O��findNames���܂܂�Ă��邩�AfindNotNames���܂܂�Ă��Ȃ��I�u�W�F�N�g�̃|�C���^��vector
	*/
	vector<Node*> getObjectsFromChildren(const vector<string>& findNames, const vector<string>& findNotNames = {}) const;
	/**
	* @brief ���[�g�I�u�W�F�N�g����AfindNames���܂܂�Ă��邩�AfindNotNames���܂܂�Ă��Ȃ��I�u�W�F�N�g�̃|�C���^���擾����
	* @param vector<string> findNames �܂܂�閼�O��vector
	* @param vector<string> findNotNames �܂܂�Ȃ����O��vector
	* @return vector<Node*> ���O��findNames���܂܂�Ă��邩�AfindNotNames���܂܂�Ă��Ȃ��I�u�W�F�N�g�̃|�C���^��vector
	*/
	vector<Node*> getObjectsFromRoot(const vector<string>& findNames, const vector<string>& findNotNames = {}) const;
	/**
	* @brief �q���I�u�W�F�N�g����w�肵�����O�̃I�u�W�F�N�g���擾����
	* @param string name ������I�u�W�F�N�g�̖��O
	* @return Node* �I�u�W�F�N�g�̃|�C���^
	*/
	Node* getObjectFromChildren(const string& name) const;
	/**
	* @brief ���[�g�I�u�W�F�N�g����w�肵�����O�̃I�u�W�F�N�g���擾����
	* @param string name ������I�u�W�F�N�g�̖��O
	* @return Node* �I�u�W�F�N�g�̃|�C���^
	*/
	Node* getObjectFromRoot(const string& name) const;
	/**
	* @brief �q���I�u�W�F�N�g����w�肵��ID�̃I�u�W�F�N�g���擾����
	* @param int id ������I�u�W�F�N�g��ID
	* @return Node* �I�u�W�F�N�g�̃|�C���^
	*/
	Node* getObjectFromChildren(int id) const;
	/**
	* @brief ���[�g�I�u�W�F�N�g����w�肵��ID�̃I�u�W�F�N�g���擾����
	* @param int id ������I�u�W�F�N�g��ID
	* @return Node* �I�u�W�F�N�g�̃|�C���^
	*/
	Node* getObjectFromRoot(int id) const;
	//------------------------------------------------------
	//�I�u�W�F�N�g���O�֘A
	//------------------------------------------------------
	/** @brief �����̖��O�Ǝ��g�̖��O����v���Ă����true��Ԃ� */
	bool matchingName(const string& name) const;
	/** @brief �w��̕����񂪎��g�̖��O�Ɋ܂܂�Ă����true��Ԃ� */
	bool findName(const string& name) const;
	/** 
	* @brief ���O��ύX���� 
	* @param string name �ύX��̖��O
	* @return string �ύX�O�̖��O
	*/
	string changeName(const string& name);
	/** @brief ���O��\0�ȍ~�Ɏw��̕������ǉ� */
	void appendName(const string& append);
	//------------------------------------------------------
	//�I�u�W�F�N�gID�֘A
	//------------------------------------------------------
	/** @brief ���g�̃��j�[�N��ID�������ƈ�v���Ă���Ȃ�true��Ԃ� */
	bool matchingID(int id) const;
	/** @brief �����̃I�u�W�F�N�g�����g�ƈ�v���Ă���Ȃ�true��Ԃ� */
	bool isSame(Node* obj) const;
	//------------------------------------------------------
	//�I�u�W�F�N�g�쓮��ԕύX�֘A
	//------------------------------------------------------
	//�I�u�W�F�N�g�j���\��------------------------------------
	virtual void kill();
	/** @brief �w�肵�����O�̃I�u�W�F�N�g���q������T���Ĕj���\�� */
	void killFromChildren(const string& name);
	/** @brief �w�肵�����O�̃I�u�W�F�N�g�����[�g����T���Ĕj���\�� */
	void killFromRoot(const string& name);
	/**
	* @brief �q���I�u�W�F�N�g����AfindNames���܂܂�Ă��邩�AfindNotNames���܂܂�Ă��Ȃ��I�u�W�F�N�g�̔j���\�������
	* @param vector<string> findNames �܂܂�閼�O��vector
	* @param vector<string> findNotNames �܂܂�Ȃ����O��vector
	*/
	void killObjectsFromChildren(const vector<string>& findNames, const vector<string>& findNotNames = {});
	/**
	* @brief ���[�g�I�u�W�F�N�g����AfindNames���܂܂�Ă��邩�AfindNotNames���܂܂�Ă��Ȃ��I�u�W�F�N�g�̔j���\�������
	* @param vector<string> findNames �܂܂�閼�O��vector
	* @param vector<string> findNotNames �܂܂�Ȃ����O��vector
	*/
	void killObjectsFromRoot(const vector<string>& findNames, const vector<string>& findNotNames = {});
	//�I�u�W�F�N�g�쓮---------------------------------------
	virtual void run();
	/** @brief �q�����܂߂��쓮 */
	virtual void runAll();
	/** @brief �w�肵�����O�̃I�u�W�F�N�g���q������T���ċ쓮 */
	void runFromChildren(const string& name);
	/** @brief �w�肵�����O�̃I�u�W�F�N�g�����[�g����T���ċ쓮 */
	void runFromRoot(const string& name);
	/**
	* @brief �q���I�u�W�F�N�g����AfindNames���܂܂�Ă��邩�AfindNotNames���܂܂�Ă��Ȃ��I�u�W�F�N�g���쓮
	* @param vector<string> findNames �܂܂�閼�O��vector
	* @param vector<string> findNotNames �܂܂�Ȃ����O��vector
	*/
	void runObjectsFromChildren(const vector<string>& findNames, const vector<string>& findNotNames = {});
	/**
	* @brief ���[�g�I�u�W�F�N�g����AfindNames���܂܂�Ă��邩�AfindNotNames���܂܂�Ă��Ȃ��I�u�W�F�N�g���쓮
	* @param vector<string> findNames �܂܂�閼�O��vector
	* @param vector<string> findNotNames �܂܂�Ȃ����O��vector
	*/
	void runObjectsFromRoot(const vector<string>& findNames, const vector<string>& findNotNames = {});
	//�I�u�W�F�N�g��~----------------------------------------
	virtual void stop();
	/** @brief �q�����܂߂���~ */
	void stopAll();
	/** @brief �w�肵�����O�̃I�u�W�F�N�g���q������T���Ē�~ */
	void stopFromChildren(const string& name);
	/** @brief �w�肵�����O�̃I�u�W�F�N�g�����[�g����T���Ē�~ */
	void stopFromRoot(const string& name);
	/**
	* @brief �q���I�u�W�F�N�g����AfindNames���܂܂�Ă��邩�AfindNotNames���܂܂�Ă��Ȃ��I�u�W�F�N�g���~
	* @param vector<string> findNames �܂܂�閼�O��vector
	* @param vector<string> findNotNames �܂܂�Ȃ����O��vector
	*/
	void stopObjectsFromChildren(const vector<string>& findNames, const vector<string>& findNotNames = {});
	/**
	* @brief ���[�g�I�u�W�F�N�g����AfindNames���܂܂�Ă��邩�AfindNotNames���܂܂�Ă��Ȃ��I�u�W�F�N�g���~
	* @param vector<string> findNames �܂܂�閼�O��vector
	* @param vector<string> findNotNames �܂܂�Ȃ����O��vector
	*/
	void stopObjectsFromRoot(const vector<string>& findNames, const vector<string>& findNotNames = {});
	//�I�u�W�F�N�g��Q������----------------------------------
	virtual void sleep(int sleepCnt);
	/** @brief �q�����܂߂��X���[�v */
	void sleepAll(int sleepCnt);
	/** @brief �w�肵�����O�̃I�u�W�F�N�g���q������T���ăX���[�v */
	void sleepFromChildren(const string& name, int sleepCnt);
	/** @brief �w�肵�����O�̃I�u�W�F�N�g�����[�g����T���ăX���[�v */
	void sleepFromRoot(const string& name, int sleepCnt);
	/**
	* @brief �q���I�u�W�F�N�g����AfindNames���܂܂�Ă��邩�AfindNotNames���܂܂�Ă��Ȃ��I�u�W�F�N�g���X���[�v
	* @param vector<string> findNames �܂܂�閼�O��vector
	* @param vector<string> findNotNames �܂܂�Ȃ����O��vector
	* @param int sleepCnt �Q������t���[����
	*/
	void sleepObjectsFromChildren(const vector<string>& findNames, const  vector<string>& findNotNames, int sleepCnt);
	/**
	* @brief ���[�g�I�u�W�F�N�g����AfindNames���܂܂�Ă��邩�AfindNotNames���܂܂�Ă��Ȃ��I�u�W�F�N�g���X���[�v
	* @param vector<string> findNames �܂܂�閼�O��vector
	* @param vector<string> findNotNames �܂܂�Ȃ����O��vector
	* @param int sleepCnt �Q������t���[����
	*/
	void sleepObjectsFromRoot(const vector<string>& findNames, const vector<string>& findNotNames, int sleepCnt);
	/** @brief �X���[�v����̕��A�ۏؗp */
	virtual void resume();
	//------------------------------------------------------
	//�A�N�Z�T
	//------------------------------------------------------
	int ID() const;
	int priority() const;
	const string& name() const;
	State state() const;
	bool isRunning() const;
	bool isStop() const;
	bool isSleep() const;
	bool isDestroy() const;
	bool isDead() const;
	void changePriority(int priority);
	//-----------------------------------------------------------------------
	//��r�p���q�֐�
	//-----------------------------------------------------------------------
	static bool greaterPriority(const Node* lh, const Node* rh)
	{
		return lh->priority() > rh->priority();
	}
	static bool lessPriority(const Node* lh, const Node* rh)
	{
		return lh->priority() < rh->priority();
	}
	//-----------------------------------------------------------------------
	//���b�Z�[�W����M
	//-----------------------------------------------------------------------
	virtual int receiveMsg(Node* sender, const string& msg);
	virtual int postMsg(Node* receiver, const string& msg);

private:
	//------------------------------------------------------
	//�����o�ϐ�
	//------------------------------------------------------
	static int		uid_;			//! ���j�[�NID�A��������ƃC���N�������g
	int				id_;			//! �I�u�W�F�N�gID�A�����p
	int				hierarchy_;		//! �K�w�A���[�g��1�A�q���ɂȂ�ɂ�+1
	float			priority_;		//! �`��D�揇�ʁA�����قǎ�O�ɕ`��
	State			state_;			//! �쓮���
	string			name_;			//!	���O�A�����p
	int				sleepCnt_;		//! �Q������t���[�����A�ʏ펞��0

	Node*			selfPtr_;		//!	���g�̃|�C���^
	Node*			parentPtr_;		//!	�e�̃|�C���^
	vector<Node*>	children_;		//!	�q���I�u�W�F�N�g
	vector<Node*>	insert_;		//! �q���ɒǉ�����I�u�W�F�N�g
	//------------------------------------------------------

	//------------------------------------------------------
	//�e�q�֌W�\�z�p
	//------------------------------------------------------
	/** @brief �������Ƀ��j�[�NID��ݒ� */
	void initID();
	//------------------------------------------------------
	/** @brief �e�q�֌W���\�z����	*/
	virtual void init();
	/** @brief �ǉ�����I�u�W�F�N�g���q���ɒǉ� */
	void insert();

	//------------------------------------------------------
	//update�֘A
	//------------------------------------------------------
	/** @brief Run�̎��ɌĂ΂��*/
	virtual void update();
	/** @brief Stop�̎��ɌĂ΂�� */
	virtual void updateStop();
	/** @brief Sleep�̎��ɌĂ΂�� */
	virtual void updateSleep();
	/** @brief Destroy�̎��ɌĂ΂�� */
	virtual void updateDestroy();
	/** @brief �q�����܂߂��X�V���� */
	virtual void updateChildObjects();
	/** @brief Run�̎��ɌĂ΂��q�����܂߂��X�V���� */
	void updateWithChildrenRun();
	/** @brief Stop�̎��ɌĂ΂��q�����܂߂��X�V���� */
	void updateWithChildrenStop();
	/** @brief Sleep�̎��ɌĂ΂��q�����܂߂��X�V���� */
	void updateWithChildrenSleep();
	/** @brief Destroy�̎��ɌĂ΂��q�����܂߂��X�V���� */
	void updateWithChildrenDestroy();
	/** @brief ���g�̋쓮��Ԃɉ����ČĂяo���X�V������؂�ւ��� */
	virtual void updateSelect();
	/** @brief ���[�g�݂̂ŌĂԂ��� */
	void updateWithChildren();
	//-----------------------------------------------------------------------
	//render�֘A
	//-----------------------------------------------------------------------
	/** @brief Run�̎��ɌĂ΂��*/
	virtual void render();
	/** @brief Stop�̎��ɌĂ΂�� */
	virtual void renderStop();
	/** @brief Sleep�̎��ɌĂ΂�� */
	virtual void renderSleep();
	/** @brief Destroy�̎��ɌĂ΂�� */
	virtual void renderDestroy();
	/** @brief �q�����܂߂��`�揈�� */
	virtual void renderChildObjects();
	/** @brief Run�̎��ɌĂ΂��q�����܂߂��`�揈�� */
	void renderWithChildrenRun();
	/** @brief Stop�̎��ɌĂ΂��q�����܂߂��`�揈�� */
	void renderWithChildrenStop();
	/** @brief Sleep�̎��ɌĂ΂��q�����܂߂��`�揈�� */
	void renderWithChildrenSleep();
	/** @brief Destroy�̎��ɌĂ΂��q�����܂߂��`�揈�� */
	void renderWithChildrenDestroy();
	/** @brief ���g�̋쓮��Ԃɉ����ČĂяo���`�揈����؂�ւ��� */
	virtual void renderSelect();
	/** @brief ���[�g�݂̂ŌĂԂ��� */
	virtual void renderWithChildren();

public:
};

template<typename Ptr>
inline Node* Node::insertToParent(Ptr * obj){
	auto parent = getParentPtr();
	if (!parent) { assert(!"�e�̃|�C���^������܂���"); }
	parent->insertAsChild(obj);
	return obj;
}

template<typename Ptr>
inline Node * Node::insertToParentStop(Ptr * obj) {
	insertToParent(obj);
	obj->stop();
	return obj;
}

template<typename Ptr>
inline Node * Node::insertToParentSleep(Ptr * obj, int sleepCnt){
	insertToParent(obj);
	obj->sleep(sleepCnt);
	return obj;
}

template<typename Ptr>
inline Node * Node::insertAsChild(Ptr * obj) {
	obj->setSelfPtr(obj);
	obj->setParentPtr(selfPtr());
	obj->hierarchy_ = hierarchy_ + 1;
	insert_.push_back(obj);
	return obj;
}

template<typename Ptr>
inline Node * Node::insertAsChildStop(Ptr * obj){
	insertAsChild(obj);
	obj->stop();
	return obj;
}

template<typename Ptr>
inline Node * Node::insertAsChildSleep(Ptr * obj, int sleepCnt) {
	insertAsChild(obj);
	obj->sleep(sleepCnt);
	return obj;
}
