# RuleBasedGraph
Given a defined graph and a ruleset, the application shall be able to modify original graph.
# 
##### subgraph descriptor
{<start_node>:<comma_separated_list_of_end_nodes>}
"0" node_id in a subgraph means that node is null in the implementation
# rules usable:
## add
add subgraph to the graph:
modifier subgraph can be started from an existing node in the graph
or can be ends on an allready existing node

**add** :{<existing_node_started_from>:<existing_node_ends_with>}{<modifier_subgraph>}


## insert
insert subgraph between connected nodes (node1 and node2)

**insert**:{<node1_id>:<node2_id>}{<subgraph descriptor>}
## replace
replace originap subgraph to a new one

**replace**:{<original_subgraph_descriptor>}{<subgraph_descriptor>}	 

## change
change  originap node to a new one

**change**:{<original_node_id>:0}{<changed_node_id>:0}	

## delete
delete subgraph from the graph

**delete**:{<original_subgraph_descriptor_to_delete>}

## 

