core = 8.x
api = 2

defaults[projects][subdir] = "contrib"

; Contrib modules
projects[admin_toolbar][version] = 1.18
projects[better_normalizers][version] = '1.0-beta2'
projects[ctools][version] = 3.0-alpha27
projects[default_content][version] = '1.0-alpha4'
projects[ds][version] = '2.6'
projects[embed][version] = '1.0-rc3'
projects[entity][version] = '1.0-alpha4'
projects[entity_browser][version] = '1.0-rc2'
projects[entity_embed][version] = '1.0-beta2'
projects[fences][version] = '2.0-alpha1'
projects[inline_entity_form][version] = '1.0-beta1'
projects[layout_plugin][version] = 1.0-alpha23
projects[link_attributes][version] = '1.0'
projects[media_entity][version] = '1.6'
projects[media_entity_browser][version] = '1.0-beta3'
projects[media_entity_browser][patch][] = 'https://www.drupal.org/files/issues/meb_add_config-2850574-2.patch'
projects[media_entity_image][version] = '1.2'
projects[metatag][version] = '1.0'
projects[page_manager][patch][] = https://www.drupal.org/files/issues/page_manager-block_content_contextual-2601004-14.patch
projects[page_manager][version] = '1.0-alpha24'
projects[panels][version] = '3.0-beta6'
projects[password_policy][version] = '3.0-alpha3'
projects[pathauto][version] = '1.0-rc1'
projects[scheduled_updates][version] = '1.0-alpha6'
projects[simple_sitemap][version] = '2.8'
projects[token][version] = '1.0-rc1'
projects[twitter_block][version] = 2.1
projects[video_embed_field][version] = '1.4'
projects[workbench_moderation][version] = '1.2'

; Development Modules
projects[config_devel][version] = '1.0'
projects[config_devel][subdir] = 'development'

; Themes
projects[agov_base][version] = '1.2'
projects[agov_whitlam][version] = '1.3'
