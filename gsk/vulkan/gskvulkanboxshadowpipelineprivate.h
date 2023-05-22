#pragma once

#include <graphene.h>

#include "gskvulkanpipelineprivate.h"
#include "gskroundedrect.h"

G_BEGIN_DECLS

typedef struct _GskVulkanBoxShadowPipelineLayout GskVulkanBoxShadowPipelineLayout;

#define GSK_TYPE_VULKAN_BOX_SHADOW_PIPELINE (gsk_vulkan_box_shadow_pipeline_get_type ())

G_DECLARE_FINAL_TYPE (GskVulkanBoxShadowPipeline, gsk_vulkan_box_shadow_pipeline, GSK, VULKAN_BOX_SHADOW_PIPELINE, GskVulkanPipeline)

GskVulkanPipeline *     gsk_vulkan_box_shadow_pipeline_new              (GdkVulkanContext               *context,
                                                                         VkPipelineLayout                layout,
                                                                         const char                     *shader_name,
                                                                         VkRenderPass                    render_pass);

void                    gsk_vulkan_box_shadow_pipeline_collect_vertex_data (GskVulkanBoxShadowPipeline  *pipeline,
                                                                         guchar                         *data,
                                                                         const graphene_point_t         *offset,
                                                                         const GskRoundedRect           *outline,
                                                                         const GdkRGBA                  *color,
                                                                         float                           dx,
                                                                         float                           dy,
                                                                         float                           spread,
                                                                         float                           blur_radius);

gsize                   gsk_vulkan_box_shadow_pipeline_draw             (GskVulkanBoxShadowPipeline     *pipeline,
                                                                         VkCommandBuffer                 command_buffer,
                                                                         gsize                           offset,
                                                                         gsize                           n_commands);

G_END_DECLS

