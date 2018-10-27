/**
* @file SceneInfo.hpp
* @brief �V�[���̊��N���X�A�C���^�[�t�F�C�X���`����
* @author yokota0717
* @date 2018.10.26
*/


#pragma once
#include <unordered_map>
#include <any>

namespace Scene {
	/**
	* @brief �V�[�����A����ŃV�[���𔻕ʂ���
	*/
	enum class SceneName {
		NON,			//����`
		TITLE,			//�^�C�g��
		GAME,			//�Q�[���{��
		BACK_SCENE,		//�X�^�b�N�ɑO�̃V�[�����c���Ă���Ζ߂�
	};

	/**
	* @brief �V�[���J�ڎ��ɓn���p�����[�^
	*/
	class Parameter final {
	private:
		/**
		* @brief �V�[���J�ڎ��ɓn���p�����[�^�̃R���e�i
		*/
		std::unordered_map<std::string, std::any> map_;
	public:
		Parameter() = default;
		/**
		* @brief �R���e�i�ɗv�f��ǉ�����
		* - �e���v���[�g�����ɑ}���������l������
		* @param key �L�[�ƂȂ閼�O
		* @param value �}���������l
		*/
		template<typename ValueType>
		void add(const std::string& key, const ValueType value) {
			map[key] = value;
		}
		/**
		* @ brief �R���e�i�ɂ���w�肵���L�[�̒l���擾����
		* - �e���v���[�g�����Ŏ擾�������l��Ԃ�
		*/
		template<typename ValueType>
		[[nodiscard]] const ValueType get(const std::string& key) {
			try {
				auto it = map_.find(key);
				if (it == map_.end()) {
					throw "�L�[������܂���";
				}
				return std::any_cast<ValueType>(it->second);
			}
			catch (std::string& errMsg) {
				std::cout << errMsg << std::endl;
			}
		}
	};

	/**
	* @brief �V�[���ύX���Ɏw�肷��V�[�������t���O
	*/
	enum class StackPopFlag {
		POP,		//���݂̃V�[�����|�b�v����
		NON,		//���݂̃V�[�����X�^�b�N�����܂܂ɂ���
		ALL_CLEAR,	//���ׂẴV�[������������
	};

	/**
	* @brief �R�[���o�b�N����C���^�[�t�F�C�X�N���X
	*/
	class IOnSceneChangedListener {
	public:
		IOnSceneChangedListener() = default;
		virtual ~IOnSceneChangedListener() = default;
		/**
		* @brief �V�[����ύX����֐�
		* @param scene ���̃V�[��
		* @param param ���̃V�[���ɓn���p�����[�^
		* @param stackPopFlag ���g�̃X�^�b�N���N���A���邩
		*/
		virtual void onSceneChanged(const SceneName& scene, const Parameter* param, const StackPopFlag stackPopFlag) = 0;
	};
	/**
	* @brief �V�[���̊��N���X
	*/
	class AbstractScene {
	private:
		IOnSceneChangedListener* sceneLister_;
	public:
		AbstractScene(IOnSceneChangedListener* listener)
			:
			sceneLister_(listener)
		{}
		virtual ~AbstractScene() = default;
		IOnSceneChangedListener& callBack() const { return *sceneLister_; }
		virtual void update() = 0;
		virtual void render() = 0;
	};
}