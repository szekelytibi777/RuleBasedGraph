# RuleBasedGraph
Given a defined graph and a ruleset, the application shall be able to modify original graph.

Developed in a docker environment, the source code is compiled with the latest version of gcc
This application uses graphwiz next to x terminal for visual representation:
### executable use:
**main** _<graph_descriptor_file_path> <modifier_rules_file_path>_

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

## delete
delete subgraph from the graph

**delete**:{<descriptor_of_original_subgraph_to_delete>}




