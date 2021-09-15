#include "../h/types.h"
#include "../h/asl.h"
#include "../h/pcb.h"

semd_PTR semdFreeList;
HIDDEN semd_PTR semdActiveList;
HIDDEN semd_PTR semd_h, semdFree_h;
//
int insertBlocked(int *semAdd, pcb_t *p)
{
	semd_PTR found = searchASL(*semAdd);
	//If sema4 is currently not active 
	if(found == NULL)
	{
		/* Pseudocode
		allocate new descriptor
		insert new descriptor in the ASL
		desc->s_semAdd = semAdd;
		desc->s_procq = mkEmptyProcQ();
		return TRUE;
		 */
	}
	return FALSE;
	
}

pcb_t *removeBlocked(int *semAdd)
{
	if(searchASL(semdTable, semAdd) == NULL)
	{
		return NULL;
	}
	pcb_t *removedQ = semdTable[semAdd]->s_procQ;
	semd_t *removedS = semdTable[semAdd];
	semdTable[semAdd]->s_procQ = NULL;
	semdTable[semAdd] = NULL;
	return *removedQ;
}

pcb_t *outBlocked(pcb_t *p)
{
	// semd_PTR semaphore = p->p_semAdd;
	/* Pseudocode 
		if(  p->p_semAdd != semaphore->s_procq->p_next)
		{
			return NULL;
		}
		return p;
	*/
}

pcb_t *headBlocked(int *semAdd)
{
	if(!(searchASL(semdTable, semAdd)) || semdTable[semAdd]->s_procQ == NULL)
	{
		return NULL;
	}
	else
	{
		if(searchASL(semdTable,semAdd))
		{
			return semdTable[semAdd]->s_procQ;
		}
	}
}

initASL()
{
	static semd_t semdTable[MAXPROC];
	
	semd_PTR dummy_head;
	dummy_head->s_semAdd = 0;
	dummy_head->s_procQ = NULL;
	
	semd_PTR dummy_tail;
	dummy_tail->s_semAdd = INT_MAX;
	dummy_tail->s_procQ = NULL;
	dummy_tail->s_next = NULL;
	dummy_head->s_next = dummy_tail;
	semdActiveList->s_next = 
	for(int i=1; i<MAXPROC; i++)
	{
		insertBlocked(;
	}
	
	
}
      
HIDDEN semd_PTR searchASL(int *semAdd)
{
	for(int i=0; i<MAXPROC+2; i++)
	{
		if(semdTable[i]==*semAdd)
		{
			return semdTable[i];
		}
		
	}
	return NULL;
}
