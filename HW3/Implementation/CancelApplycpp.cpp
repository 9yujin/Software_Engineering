#include "RequirementSystem.h"

/*
Function : CancelApply
Description : CancelApply class constructer
Return type :
Parameters  :
*/
CancelApply::CancelApply()
{
	CancelApplyUi cancelApplyUi;
	cancelApplyUi.selectCancelApply(this);
}

/*
Function : callCancelApply
Description : call fuction of CancelApply
Return type :
Parameters  : CommonMember * , string
*/
void CancelApply::callCancelApply(MemberList* memberList, CommonMember* commonMember, string &companyName, string companyNum, string &work)
{
	ApplyList* applyList = commonMember->getApplyList();
	int applyNum = applyList->getNumOfApply();
	Apply** apply = applyList->listApplies();

	for (int i = 0; i < applyNum; i++)
	{
		if (apply[i]->getCompanyNum() == companyNum)
		{
			companyName = apply[i]->getCompanyName();
			work = apply[i]->getWork();
			applyList->deleteApply(i);	//���� ���

			//employment���� ��� �ݿ�
			Member** members = memberList->getMembers();
			for (int i = 0; i < memberList->getMemberNum(); i++)
			{
				if (members[i]->getIsCompany() == true)	//company���
				{
					Company* company = (Company*)members[i];
					if (company->getCompanyName() == companyName)	//���� ����� company���
					{
						company->getEmploymentList()->listEmployments()[0]->minusApplyNum();	//ȸ�� ���ÿ� ä�� 1���̹Ƿ�[0], �����ڼ�--
						return;
					}
				}
			}
	
		}
	}
}