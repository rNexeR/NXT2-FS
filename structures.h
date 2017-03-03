#define uint8 short short int
#define uint16 unsigned short int
#define uint32 unsigned int

struct s_superblock{
	uint32 s_inodes_count;
	uint32 s_blocks_count;
	uint32 s_r_blocks_count;
	uint32 s_free_block_count;
	uint32 s_free_inodes_count;
	uint32 s_first_data_block;
	uint32 s_log_block_size;
	uint32 s_log_frag_size;
	uint32 s_blocks_per_group;
	uint32 s_flags_per_group;
	uint32 s_inodes_per_group;
	uint32 s_mtime;
	uint32 s_wtime;
	uint16 s_mnt_count;
	uint16 s_max_mnt_count;
	uint16 s_magic;
	uint16 s_state;
	uint16 s_errors;
	uint16 s_minor_rev_level; //?
	uint32 s_lastcheck;
	uint32 s_checkinterval;
	uint32 s_creator_os;
	uint32 s_rev_level;
	uint16 s_def_resuid;
	uint16 s_def_resgid;
	uint32 s_firts_inode;
	uint16 s_inode_size;
};

struct s_block_group_descriptor{
	uint32 bg_block_bitmap;
	uint32 bg_inode_bitmap;
	uint32 bg_inode_table;
	uint16 bg_free_blocks_count;
	uint16 bg_free_inodes_count;
	uint16 bg_used_dirs_count;
	
};