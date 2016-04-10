#ifndef CSKELETON_H
#define CSKELETON_H

#include "CAnimation.h"
#include "CResource.h"
#include "Core/Render/FRenderOptions.h"
#include <Common/TString.h>
#include <Common/types.h>
#include <Math/CRay.h>
#include <Math/CVector3f.h>

class CBoneTransformData;
class CSkeleton;

class CBone
{
    friend class CSkeletonLoader;

    CSkeleton *mpSkeleton;
    CBone *mpParent;
    std::vector<CBone*> mChildren;
    u32 mID;
    CVector3f mPosition;
    TString mName;

public:
    CBone(CSkeleton *pSkel);
    void UpdateTransform(CBoneTransformData& rData, CAnimation *pAnim, float Time, bool AnchorRoot);
    bool IsRoot() const;

    // Accessors
    inline CSkeleton* Skeleton() const          { return mpSkeleton; }
    inline CBone* Parent() const                { return mpParent; }
    inline u32 NumChildren() const              { return mChildren.size(); }
    inline CBone* ChildByIndex(u32 Index) const { return mChildren[Index]; }
    inline u32 ID() const                       { return mID; }
    inline CVector3f Position() const           { return mPosition; }
    inline TString Name() const                 { return mName; }
};

class CSkeleton : public CResource
{
    DECLARE_RESOURCE_TYPE(eSkeleton)
    friend class CSkeletonLoader;

    CBone *mpRootBone;
    std::vector<CBone*> mBones;

    static const float skSphereRadius;

public:
    CSkeleton();
    ~CSkeleton();
    void UpdateTransform(CBoneTransformData& rData, CAnimation *pAnim, float Time, bool AnchorRoot);
    CBone* BoneByID(u32 BoneID) const;
    u32 MaxBoneID() const;

    void Draw(FRenderOptions Options, const CBoneTransformData& rkData);
    std::pair<s32,float> RayIntersect(const CRay& rkRay, const CBoneTransformData& rkData);

    inline u32 NumBones() const { return mBones.size(); }
};

#endif // CSKELETON_H