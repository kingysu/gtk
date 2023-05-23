#pragma once

#include <graphene.h>

#include "gskvulkanpipelineprivate.h"

G_BEGIN_DECLS

typedef struct _GskVulkanTexturePipelineLayout GskVulkanTexturePipelineLayout;

#define GSK_TYPE_VULKAN_TEXTURE_PIPELINE (gsk_vulkan_texture_pipeline_get_type ())

G_DECLARE_FINAL_TYPE (GskVulkanTexturePipeline, gsk_vulkan_texture_pipeline, GSK, VULKAN_TEXTURE_PIPELINE, GskVulkanPipeline)

GskVulkanPipeline *     gsk_vulkan_texture_pipeline_new                 (GdkVulkanContext         *context,
                                                                         VkPipelineLayout          layout,
                                                                         const char               *shader_name,
                                                                         VkRenderPass              render_pass);

void                    gsk_vulkan_texture_pipeline_collect_vertex_data (GskVulkanTexturePipeline *pipeline,
                                                                         guchar                   *data,
                                                                         guint32                   tex_id[2],
                                                                         const graphene_point_t   *offset,
                                                                         const graphene_rect_t    *rect,
                                                                         const graphene_rect_t    *tex_rect);
gsize                   gsk_vulkan_texture_pipeline_draw                (GskVulkanTexturePipeline *pipeline,
                                                                         VkCommandBuffer           command_buffer,
                                                                         gsize                     offset,
                                                                         gsize                     n_commands);

G_END_DECLS

