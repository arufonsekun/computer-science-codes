select candidate.name, trunc(((math*2) + (specific*3) + (project_plan*5))/10, 2) avg from candidate join score on candidate.id=score.candidate_id order by avg desc;
