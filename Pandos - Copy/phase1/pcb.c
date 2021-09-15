#include "../h/types.h"
#include "../h/pcb.h"

HIDDEN pcb_t *pcbFree_h;


/* Allocation and Deallocation Methods */
void freePcb(pcb_PTR p)
{
	insertProcQ(&(pcbFree_h), p);
}
	
pcb_PTR allocPCB()
{
	if(pcbFree_h == NULL)
	{
		return NULL;
	}
	pcb_PTR temp = removeProcQ(&(pcbFree_h));
	temp->p_next = NULL;
	temp->p_prev = NULL;
	temp->p_prnt = NULL;
	temp->p_child = NULL;
	temp->p_sib = NULL;
	temp->p_s = NULL;
	temp->p_semAdd = 0;
	return temp;
}

void initPcbs()
{
	static pcb_t foo[MAXPROC];
	pcbList_h = NULL;
	for(int i = 0; i < MAXPROC; i++)
	{
		freeProc(&(foo[i]));
	}
}

/* Process Queue Maintenance Methods */
pcb_PTR mkEmptyProcQ () 
{
	return (NULL);
}

int emptyProcQ (pcb_PTR tp) 
{
	if(tp == NULL)
	{	return TRUE;	}
	else
	{	return FALSE;	}
}

 
void insertProcQ (pcb_PTR tp, pcb_PTR p)
{	
   	/* if q empty then tail pointer points to p */ 
	if(emptyProcQ(tp))
	{
		p->p_next=tp; /* Def not correct (will fix) */
		tp=p;
	}
	/* if not empty update tp to be */
	else
	{
		 p->p_next = (*tp)->p_next;
		 (*tp)->p_next=p;
		 tp=p;
	}
}
pcb_PTR removeProcQ (pcb_PTR tp)
{
	
	pcb_PTR temp = tp->p_next ;
	/* only one element */
	return (outProcQ(tp, temp);
}


pcb_PTR outProcQ (pcb_PTR tp, pcb_PTR p)
{

	if(emptyProcQ(tp))
	{
		return NULL;
	}
	pcb_PTR temp = (*tp)->p_next;
	if(temp == p){
	
		/* only one element */
		if(temp->p_next == NULL)
		{
		(*tp)->p_next = NULL;
		tp = mkEmptyProcQ();
		return temp;
		}
		(*tp)->p_next = temp->p_next;
		return temp;
	}
	for(int i = 0;i<MAXPROC;i++){
		if(temp->p_next == p){
			temp->p_next=p->next; /* p->p_prev->p_next = p->p_next; */
			return p;
		}
		temp = temp->p_next; 
	}
	/* p not found in queue */
	return NULL;
}

pcb_PTR headProcQ (pcb_PTR tp)
{
	pcb_PTR firstPCB;
	pcb_PTR firstPCB=tp->p_next;
	if(tp->firstPCB != NULL) /* changed tail to firstPCB */
	{	return firstPCB;	}
	else
	{	return NULL;		}
}

/* Process Tree Maintenance Methods */
int emptyChild (pcb_PTR p)
{
 	/* Return 1 if true. Else, return 0. */
 	if(p->p_child==NULL)
	{
 		return TRUE;
 	}
 	else
 	{
	 	return FALSE;
 	}
}

void insertChild (pcb_PTR prnt, pcb_PTR p)
{
	pcb_PTR child = prnt->p_child;
	/* No children */
	if(child==NULL)
	{
		prnt->p_child = p;
	}
	/* One or more children */
	p->p_sib = prnt->p_child;
	prnt->p_child = p;
	
}

pcb_PTR removeChild (pcb_PTR p)
{
	pcb_t sib = p->p_child->p_sib;
	if(p->p_child==NULL)
		return NULL; 
	else
	{
		/* Only one child */
		if(sib == NULL)
		{
			pcb_t removed = (*p)->p_child;
			(*p)->p_child = NULL;
			(*p) = NULL; /* changed tp to *p */
			return removed;
		}
		
		/* More than one child */
		pcb_t removed = (*p).p_child; /* changed -> to . */
		(*p).p_child = sib; /* changed -> to . */
		return removed;
		
	}
}

pcb_PTR outChild (pcb_PTR p)
{
	if(p->p_prnt == NULL)
	{
		return NULL;
	}
	if(p->p_prnt->p_child == p)
	{
		return removeChild(p);
	}
	pcb_t removed = p;
	
	
	
}
