#include <proposals/proposal_factory.hpp>
#include <proposals/proposal.hpp>
#include <proposals/badge_proposal.hpp>
#include <proposals/badge_assignment_proposal.hpp>
#include <proposals/role_proposal.hpp>
#include <proposals/payout_proposal.hpp>
#include <proposals/assignment_proposal.hpp>
#include <proposals/attestation_proposal.hpp>
#include <common.hpp>

namespace hypha
{
    Proposal* ProposalFactory::Factory(dao& dao, const name &proposal_type)
    {
        switch (proposal_type.value)
        {
        case common::BADGE_NAME.value:
            return new BadgeProposal(dao);
        
        case common::ASSIGN_BADGE.value:
            return new BadgeAssignmentProposal(dao);

        case common::ROLE_NAME.value:
            return new RoleProposal(dao);
        
        case common::ASSIGNMENT.value:
            return new AssignmentProposal(dao);

        case common::PAYOUT.value:
            return new PayoutProposal(dao);

        case common::ATTESTATION.value:
            return new AttestationProposal(dao);
        }

        eosio::check(false, "Unknown proposal_type");
        return nullptr;
    }
} // namespace hypha