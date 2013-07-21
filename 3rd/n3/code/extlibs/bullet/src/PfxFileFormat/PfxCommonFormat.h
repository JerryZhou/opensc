/* [SCE CONFIDENTIAL DOCUMENT]
 * $PSLibId$
 *                Copyright (C) 2008 Sony Computer Entertainment Inc.
 *                                                All Rights Reserved.
 */

#ifndef __PFX_COMMON_FORMAT_H__
#define __PFX_COMMON_FORMAT_H__

#include "PfxCommonTypes.h"

#include <string>
#include <vector>
#include <map>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// �t�H�[�}�b�g���

#define PFX_FORMAT_VENDER	"Sony Computer Entertainment"
#define PFX_FORMAT_VERSION	"1.0.0"

///////////////////////////////////////////////////////////////////////////////
// ���̂Ŏg����v�f�̎��

// �`��̎��
enum PfxRigShapeType {
	RigShapeTypeSphere = 0,	// ��
	RigShapeTypeBox,		// �{�b�N�X
	RigShapeTypeCapsule,	// �J�v�Z��
	RigShapeTypeConvexMesh,	// �ʃ|���S��
	RigShapeTypeLargeMesh,	// ��K�̓��b�V��
};

// ���̓���̎��
enum PfxRigMoveType {
	RigMoveTypeFixed = 0,	// �Œ�
	RigMoveTypeActive,		// �A�N�e�B�u
	RigMoveTypeKeyframe,	// �L�[�t���[��
	RigMoveTypeOneWay,		// �����
	RigMoveTypeTrigger,		// �g���K
};

// �W���C���g�̎��
enum PfxRigJointType {
	RigJointTypeBall = 0,	// �{�[���W���C���g
	RigJointTypeChain,		// �`�F�C���W���C���g
	RigJointTypeSlider,		// �X���C�_�[�W���C���g
	RigJointTypeHinge,		// �q���W�W���C���g
	RigJointTypeFix,		// �Œ�W���C���g
	RigJointTypeUniversal,	// ���j�o�[�T���W���C���g
	RigJointTypeAnimation,	// �A�j���[�V�����W���C���g
	RigJointTypeDistance,	// ��苗���ɕۂW���C���g
	RigJointType6DOF,		// 6���R�x�W���C���g
	RigJointTypeConeTwist,  // �R�[���c�C�X�g�W���C���g
};

///////////////////////////////////////////////////////////////////////////////
// PfxRigWorldInfo

struct PfxRigWorldInfo {
	// �I�u�W�F�N�g�̍ő吔
	PfxUInt32 maxInstances;			// ���̃C���X�^���X�̍ő吔
	PfxUInt32 maxDynBodies;			// ���̂̍ő吔
	PfxUInt32 maxJoints;				// �W���C���g�̍ő吔
	PfxUInt32 maxSprings;			// �X�v�����O�̍ő吔
	PfxUInt32 maxContactPairs;		// �R���^�N�g�y�A�̍ő吔

	// ���[���h
	PfxFloat3  worldCenter;			// ���[���h�̒��S
	PfxFloat3  worldExtent;			// ���[���h�̍L��
	PfxFloat3  gravity;				// �d��

	// �V�~�����[�V����
	PfxUInt8 subStepCount;			// �T�u�X�e�b�v��
	PfxUInt8 contactIteration;		// �R���^�N�g���Z�̔�����
	PfxUInt8 jointIteration;		// �W���C���g���Z�̔�����
	PfxFloat maxLinearVelocity;		// ���x�̍ő�l
	PfxFloat maxAngularVelocity;	// �p���x�̍ő�l
	PfxFloat separateBias;			// �ڐG���Ă��鍄�̂������������߂̃o�C�A�X�l

	// �X���[�v
	PfxBool  sleepEnable;			// �X���[�v�@�\��ON/OFF
	PfxUInt16 sleepCount;			// �X���[�v�ɓ���J�E���g
	PfxUInt16 sleepInterval;		// �X���[�v�`�F�b�N�C���^�[�o��
	PfxFloat sleepLinearVelocity;	// �X���[�v�ɓ��邽�߂̕��i���x
	PfxFloat sleepAngularVelocity;	// �X���[�v�ɓ��邽�߂̊p���x
	PfxFloat wakeLinearVelocity;	// �N���邽�߂̕��i���x
	PfxFloat wakeAngularVelocity;	// �N���邽�߂̊p���x
	
	
	PfxBool ccdEnable;				// �A���I�Փ˔����ON/OFF
	PfxBool deformMeshEnable;		// �ό`���b�V����ON/OFF
	
	PfxRigWorldInfo()
	{
		maxInstances = 550;
		maxDynBodies = 40;
		maxJoints = 600;
		maxSprings = 0;
		maxContactPairs = 5000;
		worldExtent = PfxFloat3(200.0f);
		worldCenter = PfxFloat3(0.0f,90.0f,0.0f);
		gravity = PfxFloat3(0.0f,-9.8f,0.0f);
		subStepCount = 1;
		contactIteration = 5;
		jointIteration = 8;
		maxLinearVelocity = 500.0f;
		maxAngularVelocity = 100.0f;
		separateBias = 0.2f;
		sleepEnable = true;
		sleepLinearVelocity = 0.1f;
		sleepAngularVelocity = 0.1f;
		sleepCount = 100;
		sleepInterval = 300;
		wakeLinearVelocity = 0.2f;
		wakeAngularVelocity = 0.2f;
		ccdEnable = false;
		deformMeshEnable = false;
	}
};

///////////////////////////////////////////////////////////////////////////////
// PfxRigShapeInfo

struct PfxRigShapeInfo {
	PfxRigShapeType shapeType : 8;
	PfxUInt32 contactFilterSelf;
	PfxUInt32 contactFilterTarget;
	PfxFloat4 relativeOrientation;
	PfxFloat3 relativePosition;
	union {
		PfxFloat    vfData[3];
		PfxUInt32   viData[3];
	};
	
	PfxRigShapeInfo()
	{
		shapeType = RigShapeTypeSphere;
		contactFilterSelf = 0xffffffff;
		contactFilterTarget = 0xffffffff;
		relativeOrientation = PfxFloat4(0.0f,0.0f,0.0f,1.0f);
		relativePosition = PfxFloat3(0.0f);
		viData[0] = viData[1] = viData[2] = 0;
	}
};

///////////////////////////////////////////////////////////////////////////////
// PfxRigBodyInfo

struct PfxRigBodyInfo {
	string		name;					// ����
	PfxFloat	mass;					// ����
	PfxMatrix3	inertia;				// �����e���\��
	PfxFloat	friction;				// ���C�W��
	PfxFloat	restitution;			// �����W��
	vector<PfxRigShapeInfo> shapes;		// �`��z��
	
	PfxRigBodyInfo()
	{
		name = "";
		mass = 0.0f;
		inertia.identity();
		friction = 0.6f;
		restitution = 0.2f;
	}
};

///////////////////////////////////////////////////////////////////////////////
// PfxRigStateInfo

struct PfxRigStateInfo {
	string		name;					// ����
	PfxRigMoveType	moveType;			// ����̎��
	PfxUInt32	contactFilterSelf;		// �����̃R���^�N�g�t�B���^�[
	PfxUInt32	contactFilterTarget;	// �Փː�R���^�N�g�t�B���^�[
	PfxFloat3	position;				// �ʒu
	PfxFloat4	orientation;			// ��]
	PfxFloat3 	linearVelocity;			// ���i���x
	PfxFloat3 	angularVelocity;		// ��]���x
	PfxFloat	linearDamping;			// ���i�_���s���O
	PfxFloat	angularDamping;			// ��]�_���s���O
	string		bodyName;				// ���̂Ƃ̃����N
	PfxBool		sleeping;				// �X���[�v�����ǂ���
	PfxBool		useSleep;				// �X���[�v�ۑ���
	PfxBool		useCcd;					// CCD����
	PfxBool		useContactCallback;		// �R���^�N�g�R�[���o�b�N����
	PfxBool		useSleepCallback;		// �X���[�v�R�[���o�b�N����
	
	PfxRigStateInfo()
	{
		name = "";
		moveType = RigMoveTypeFixed;
		contactFilterSelf = 0xffffffff;
		contactFilterTarget = 0xffffffff;
		position = PfxFloat3(0.0f);
		orientation = PfxFloat4(0.0f,0.0f,0.0f,1.0f);
		linearVelocity = PfxFloat3(0.0f);
		angularVelocity = PfxFloat3(0.0f);
		linearDamping = 1.0f;
		angularDamping = 0.99f;
		bodyName = "";
		sleeping = false;
		useCcd = false;
		useSleep = true;
		useContactCallback = false;
		useSleepCallback = false;
	}
};

///////////////////////////////////////////////////////////////////////////////
// PfxRigJointInfo

struct PfxRigJointInfo {
	string		name;					// ����
	PfxRigJointType	jointType;			// �W���C���g�̎��
	string		parentName;				// �e-���̃C���X�^���X
	string		childName;		 		// �q-���̃C���X�^���X
	PfxFloat3	anchor;					// ��_
	PfxFloat3	axis;					// ��

	PfxFloat	lowerLimit1;			// ���͈͂̉���
	PfxFloat	upperLimit1;			// ���͈͂̏��
	PfxFloat	lowerLimit2;			// ���͈͂̉���
	PfxFloat	upperLimit2;			// ���͈͂̏��
	PfxFloat	distance;				// Distance�W���C���g�̋���
	
	PfxFloat	linearDamping;			// ���i�_���s���O
	PfxFloat	angularDamping;			// ��]�_���s���O
	PfxFloat	linearImpulseWeight;	// ���i�C���p���X�E�F�C�g
	PfxFloat	angularImpulseWeight;	// ��]�C���p���X�E�F�C�g
	PfxFloat	linearBias;				// ���i�o�C�A�X�l
	PfxFloat	angularBias;			// ��]�o�C�A�X�l
	PfxFloat	maxLinearImpulse;		// �ő���i�C���p���X
	PfxFloat	maxAngularImpulse;		// �ő��]�C���p���X
	PfxFloat	breakableLimit;			// �W���C���g��j�� 0.0f=����
	
	PfxRigJointInfo()
	{
		name = "";
		jointType = RigJointTypeBall;
		parentName = childName = "";
		anchor = PfxFloat3(0.0f);
		axis = PfxFloat3(1.0f,0.0f,0.0f);
		lowerLimit1 = upperLimit1 = 0.0f;
		lowerLimit2 = upperLimit2 = 0.0f;
		linearDamping = angularDamping = 0.0f;
		linearImpulseWeight = angularImpulseWeight = 1.0f;
		linearBias = angularBias = 0.1f;
		maxLinearImpulse = 100.0f;
		maxAngularImpulse = 100.0f;
		breakableLimit = 0.0f;
		distance = 0.0f;
	}
};

///////////////////////////////////////////////////////////////////////////////
// PfxRigConvexMeshInfo

struct PfxRigConvexMeshInfo {
	PfxUInt32 id;
	vector<PfxFloat> verts;		// ���_�z��
	vector<PfxUInt16> indices;	// �ʃC���f�b�N�X�z��
	
	PfxRigConvexMeshInfo()
	{
		id = 0;
	}
};

///////////////////////////////////////////////////////////////////////////////
// PfxRigLargeTriMeshInfo

struct PfxRigLargeMeshInfo {
	PfxUInt32 id;
	vector<PfxFloat> verts;		// ���_�z��
	vector<PfxUInt16> indices;	// �ʃC���f�b�N�X�z��

	PfxUInt32 numFacetsLimit;	// �A�C�����h�ʐ�臒l
	PfxFloat islandsRatio; 		// �V�[���S�̂ɑ΂���A�C�����hAABB�T�C�Y�䗦
	
	PfxRigLargeMeshInfo()
	{
		id = 0;
		numFacetsLimit = 15;
		islandsRatio = 0.2f;
	}
};

///////////////////////////////////////////////////////////////////////////////
// PfxRigNonContactPairInfo

struct PfxRigNonContactPairInfo {
	string rigA,rigB;
};

///////////////////////////////////////////////////////////////////////////////
// PfxCommonFormat

class PfxCommonFormat
{
private:
	map<string,PfxUInt32>				mRigBodyMap;
	map<string,PfxUInt32>				mRigStateMap;
	map<string,PfxUInt32>				mRigJointMap;
	map<PfxUInt32,PfxUInt32>			mRigConvexMeshMap;
	map<PfxUInt32,PfxUInt32>			mRigLargeMeshMap;

protected:
	PfxRigWorldInfo						mRigWorldInfo;

	vector<PfxRigBodyInfo>				mRigBodies;
	vector<PfxRigStateInfo>				mRigStates;
	vector<PfxRigJointInfo>				mRigJoints;
	vector<PfxRigConvexMeshInfo>		mRigConvexMeshes;
	vector<PfxRigLargeMeshInfo>			mRigLargeMeshes;
	vector<PfxRigNonContactPairInfo>	mRigNonContactPairs;

public:
	void clear();
	
	void setRigWorldInfo(PfxRigWorldInfo &info);
	PfxRigWorldInfo getRigWorldInfo();

	void addRigBody(PfxRigBodyInfo &body);
	void addRigState(PfxRigStateInfo &state);
	void addRigJoint(PfxRigJointInfo &joint);
	void addRigConvexMesh(PfxRigConvexMeshInfo &convex);
	void addRigLargeMesh(PfxRigLargeMeshInfo &largemesh);
	void addRigNonContactPair(PfxRigNonContactPairInfo &info);

	int getRigBodyCount();
	int getRigStateCount();
	int getRigJointCount();
	int getConvexMeshCount();
	int getLargeMeshCount();
	int getRigNonContactPairCount();

	const PfxRigBodyInfo       &getRigBodyById(int i);
	const PfxRigStateInfo      &getRigStateById(int i);
	const PfxRigJointInfo      &getRigJointById(int i);
	const PfxRigConvexMeshInfo &getConvexMeshById(int i) const;
	const PfxRigLargeMeshInfo  &getLargeMeshById(int i) const;
	const PfxRigNonContactPairInfo  &getRigNonContactPairById(int i);

	PfxRigBodyInfo       *getRigBody(string name);
	PfxRigStateInfo      *getRigState(string name);
	PfxRigJointInfo      *getRigJoint(string name);
	PfxRigConvexMeshInfo *getConvexMesh(PfxUInt32 id);
	PfxRigLargeMeshInfo  *getLargeMesh(PfxUInt32 id);

	PfxMatrix3 calcTotalInertia(PfxRigBodyInfo &body);
};

#endif /* __PFX_COMMON_FORMAT_H__ */
